#include<stdio.h>
#include "file.h"
extern FILE*fp;
int validate(int size,char **arr) //this fuction is validate the input 
{
    
     if(((strcmp(arr[1],"-e"))==0)&& size<5)   //check the option edit or how many argument user pass
     {
         error_messages();
         return 0;
     }
     if(((strcmp(arr[1],"-v"))==0) && size<3)  //check the option view or how many argument user pass  and it valid number of argument or not
    {
      
        error_messages();
        return 0;
    }
    if(((strcmp(arr[1],"-v"))==0))
    {
        char *str=strstr(arr[2],".mp3");           //check the file extention mp3 or not
        if(str==NULL || ((strcmp(str,".mp3"))!=0))
        {
        printf("\nError: Selected file is not a valid MP3 file\n\n");
        error_messages();
        return 0;
        }
    }
    if(((strcmp(arr[1],"-e"))==0))
    {
        char *str=strstr(arr[4],".mp3");
        if(str==NULL || ((strcmp(str,".mp3"))!=0))
        {
        printf("\nError: Selected file is not a valid MP3 file\n\n");
        error_messages();
        return 0;
        } 
    }
    if((strcmp(arr[1],"-v"))==0) 
        fp=fopen(arr[2],"rb");    //open the file for reading the data
    else if((strcmp(arr[1],"-e"))==0)
        fp=fopen(arr[4],"rb");
    if(fp==NULL)
    {
        printf("\nFile not exits\n\n");
        return 0;
    }
    char ID3[4];
    fread(ID3,1,3,fp);   //read header id for check it is mp3 file or not
    ID3[3]='\0';
    if((strcmp(ID3,"ID3"))!=0) 
    {
        printf("\nError: Selected file is not a valid MP3 file\n\n");
        error_messages();
        return 0;
    }
    unsigned short ver;
    fread(&ver,2,1,fp);  //read the version 
    if(ver!=3)
    {
        printf("\nError: Unsupported ID3 version\n\n");
        error_messages();
        return 0;
    }
    fseek(fp,5,SEEK_CUR); //skip the remaining part of header
    return 1;
}
