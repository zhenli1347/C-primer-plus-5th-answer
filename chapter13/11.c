#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 1024
int main(int argc,char * argv[])
{
    char strings[MAXLEN];
    if(argc<3){
        puts("arguments error.");
        exit(1);
    }
    FILE *fp;     //打开文件
    if((fp=fopen(argv[2],"r"))==NULL){
        fprintf(stderr,"Can't open %s.\n",argv[2]);
        exit(2);
    }
    //搜索字符串
        while(fgets(strings,MAXLEN,fp)){
        if(strstr(strings,argv[1])!=NULL){
            fputs(strings,stdout);
        }
    }
    if(fclose(fp)!=0){
        fprintf(stderr,"Close %s failed.\n",argv[2]);
    }
    return 0;
}
