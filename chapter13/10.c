#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 100
int main()
{
    char file[MAXLEN];
    puts("Please enter a file name.");
    gets(file);
    FILE *fp;
    //打开文件
    if((fp=fopen(file,"r"))==NULL){
        fprintf(stdout,"Can't open %s.\n",file);
        exit(1);
    }
    //输入位置
    long location;
    char ch;
    puts("Please enter location:");
    while(scanf("%ld",&location)==1){
        fseek(fp,location,SEEK_SET);
        while((ch=getc(fp))!='\n')
            putc(ch,stdout);
        putchar('\n');
        rewind(fp);
    puts("Please enter location:");
    }

    return 0;
}
