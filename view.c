#include<stdio.h>
#include "file.h"
extern FILE *fp;
int view()  //this function is read the data and shows to the user
{
    
    for(int i=0;i<6;i++)   //we need 6 information from the mp3 file thats why loop runing 6 times
    {
        char frame_id[5];
        fread(frame_id,4,1,fp);   //read the TAGS form the file
        frame_id[4]='\0';
        unsigned int size;      // read size of one tag
        fread(&size,4,1,fp);
        convert_to_little(&size,4); //size is in the big endian data we need convert to little endian data
        char content[size]; 
        fseek(fp,2,SEEK_CUR);       //skip the flage bytes
        fread(content,size,1,fp);   //read the contain and store into a buffer
        
        print(size,frame_id,content);  //this function is to print the all information
        
   }
   fclose(fp); //after reading the full information close the file
}
void convert_to_little(void *data, int size) //this function is for convert the data big endian to little endian 
{
    if (data == NULL || size <= 1)
        return;

    unsigned char *ptr = data;

    for (int i = 0; i < size / 2; i++)
    {
        unsigned char temp = ptr[i];
        ptr[i] = ptr[size - i - 1];
        ptr[size - i - 1] = temp;
    }
}
int print(int size,char *ID3,char *content) //this is print the data in formate manner
{
    
    if((strcmp(ID3,"TPE1"))==0)
    {
        printf("Artist Name     : ");
        
    }
    else if((strcmp(ID3,"TIT2"))==0)
    {
        printf("Title           : ");
        
    }
    else if((strcmp(ID3,"TALB"))==0)
    {
        printf("Album           : ");
      
    }
    else if((strcmp(ID3,"TYER"))==0)
    {
        printf("Year            : ");
     
    }
    else if((strcmp(ID3,"TCON"))==0)
    {
        printf("Content type    : ");
      
    }
    else if((strcmp(ID3,"COMM"))==0)
    {
        printf("Composer        : ");
    }
    else 
       return 0;
    for(int i=0;i<size;i++)  //print character by character
    {
        printf("%c",content[i]);
    }
    printf("\n");

    return 0;
}



