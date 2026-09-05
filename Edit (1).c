#include<stdio.h>
#include "file.h"
extern FILE* fp;   
int edit_info(int size,char *arr[]) //This function is for edit the mp3 file
{
    FILE *fp_copy=fopen("newfile.mp3","wb"); //creat and open the file for edit and copy the data into newfile
    if(fp_copy==NULL)
    {
      printf("file not open\n");
      return 0;
    }
    rewind(fp);  //while checking the validation our file pointer pointing to another location but our need is file pointer point to the start 
    char header[10];
    fread(header,1,10,fp);
    fwrite(header,1,10,fp_copy); //copy the header and store directly into the newfile
  int count=0;
    while(1)
   {
        char frame_id[5];     //copy the frame id and store into the newfile
        fread(frame_id,4,1,fp);
        frame_id[4]='\0';
        fwrite(frame_id,4,1,fp_copy);
        unsigned int new_size=(strlen(arr[3])); //length of our new data
        if(((strcmp(frame_id,tags(arr[2])))==0)) 
        {
            unsigned int frame_size;
            fread(&frame_size,4,1,fp);     
            convert_to_little(&frame_size,4);


            unsigned int copy_size=new_size;
            convert_to_little(&new_size,4);
            fwrite(&new_size,4,1,fp_copy);
             
            char flag[3];
            fread(flag,1,2,fp);
            fwrite(flag,1,2,fp_copy);

            fwrite(arr[3],copy_size,1,fp_copy);
            fseek(fp,frame_size,SEEK_CUR);
            count++;

        }
    else if(count==0){  //ones the editing is completed then this condition is always false
        unsigned int frame_size;
        fread(&frame_size,4,1,fp);
        fwrite(&frame_size,4,1,fp_copy);

        convert_to_little(&frame_size,4);
        char flag[3];
        fread(flag,1,2,fp);
        fwrite(flag,1,2,fp_copy);
        char content[frame_size];
        fread(content,frame_size,1,fp);
        fwrite(content,frame_size,1,fp_copy);
    }
    else{   //ones the edition is completed then directly copy remain data into new file 
        char ch;
        while(fread(&ch,1,1,fp)!=0)
        {
          fwrite(&ch,1,1,fp_copy);
        }
        remove(arr[4]);        //remove the old file 
        rename("newfile.mp3",arr[4]); //rename the newfile to oldfile name 
        fclose(fp);   //after copy the hole data fclose the file pointer
        fclose(fp_copy);
        return 0;
      
        }
   }
    fclose(fp);
    fclose(fp_copy);
}
char *tags(char *str)  //this function for comparing the tags for editing
{
    if(((strcmp(str,"-t"))==0))
    {
        return "TIT2";
    }
    else if((strcmp(str,"-a"))==0)
    {
        return "TPE1";
    }
    else if((strcmp(str,"-A"))==0)
    {
        return "TALB";
    }
    else if((strcmp(str,"-g"))==0)
    {
        return "TCON";
    }
    else if((strcmp(str,"-y"))==0)
    {
        return "TYER";
    }
     else if((strcmp(str,"-c"))==0)
    {
        return "COMM";
    }
    

}