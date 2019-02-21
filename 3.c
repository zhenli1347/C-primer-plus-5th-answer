
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXLEN 100
int main()
{
    FILE *fs,*fd;
    char ch;
    char source[MAXLEN];
    char dest[MAXLEN];
    puts("please enter source file  name:");
    fscanf(stdin,"%s",source);
    puts("please enter dest  file  name:");
    fscanf(stdin,"%s",dest);
//打开文件
    if((fs=fopen(source,"r"))==NULL){
        fprintf(stderr,"%s can't open.\n",source);
        exit(1);
    }
    if((fd=fopen(dest,"w"))==NULL){
        fprintf(stderr,"%s can't open.\n",dest);
        exit(2);
    }
    while((ch=getc(fs))!=EOF){
        putc(toupper(ch),fd);
        putchar(toupper(ch));
    }
    fclose(fs);
    fclose(fd);

    return 0;

}
