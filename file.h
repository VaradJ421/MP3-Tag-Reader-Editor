#ifndef FILE_H
#define FILE_H
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void convert_to_little(void *data, int size);
int validate(int size,char **arr);
int view();
int print(int size,char *ID3,char *content);
int edit_info(int size,char *arr[]);
char *tags(char *str);
void error_messages();
void help_messages();
#endif
