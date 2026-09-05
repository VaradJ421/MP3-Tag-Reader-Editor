/*
Name : Shubham Maroti Jagtap
Project Name: MP3 Tag Reader/Editor
description :   This project is an MP3 Tag Reader and Editor developed using C programming. 
                It works with ID3v2 tags present in MP3 files to read and modify metadata such as title, 
                artist, and album. The program first validates the file format, then reads the header and extracts tag information by parsing different frames. 
                For editing, it creates a copy of the original file, updates the required tag, and writes the remaining data without modification to ensure the audio content is not corrupted. 
                This project helped me understand binary file handling, file pointers, and real-time data manipulation in C.
*/
#include<stdio.h>
#include "file.h"
FILE *fp;
int main(int argc,char *argv[])
{
   
    //The main is for only call the functions and simple validation
    if(argc<3)
    {
        error_messages();
        return 0;
    }
   
    if(((strcmp(argv[1],"--help"))==0))    
    {
        help_messages();
        return 0;
    }
    char *check[6]={"-t","-a","-A","-g","-y","-c"};
    if(((strcmp(argv[1],"-v"))!=0) && (strcmp(argv[1],"-e"))!=0)
    {
        error_messages();
        return 0;
    }
    if((validate(argc,argv))==0)
    {
         return 0;
    }
    if((strcmp(argv[1],"-v"))==0)
    {
    printf("\n--------------------------SELECTED VIEW DETAILS--------------------------------\n\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("                    MP3 TAG READER AND EDITOR FOR ID3v2\n");
    printf("-------------------------------------------------------------------------------\n");
    view(); //call view function to read and view the information
    printf("--------------------------------------------------------------------------------\n\n");
    printf("----------------------DETAILS DISPLAYED SUCCESSFULLY----------------------------\n");
    }
    else if((strcmp(argv[1],"-e"))==0)
    {
        int count=0;
        for(int i=0;i<6;i++)
        {
            if((strcmp(argv[2],check[i]))==0)
            {
                 count=1;
                 break;
            }
        }
        if(count==0)
        {
             error_messages();
             return 0;
        }
        edit_info(argc,argv);
    }

    
}
void error_messages()  //this is the formatted error message
{
        printf("---------------------------------------------------------------------------\n");
        printf("ERROR: ./a.out: INVALID ARGUMENTS\nUSAGE:\nTo view please pass like: ./a.out -v mp3filename\nTo edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c mp3filename\nTo get help pass like : ./a.out --help\n");
        printf("----------------------------------------------------------------------------\n");
        return;
}
void help_messages() //This function for print the help menu
{
    printf("\n-------------------------HELp MENU-------------------------------\n\n");
    printf("1. -v -> to view mp3 file contents\n");
    printf("2. -e -> to edit mp3 file contents\n");
    printf("         2.1. -t -> to edit song title\n");
    printf("         2.2. -a -> to edit artist name\n");
    printf("         2.3. -A -> to edit album name\n");
    printf("         2.4. -y -> to edit year\n");
    printf("         2.5. -m -> to edit content\n");
    printf("         2.1. -c -> to edit comment\n");
    printf("\n----------------------------------------------------------------------\n");
}
