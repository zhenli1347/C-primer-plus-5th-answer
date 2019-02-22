#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 1024
void tongji(FILE *fp,char ch,char *name);
int main(int argc,char * argv[])
{
    char strings[MAXLEN];
    FILE *fp;
    if(argc<2){
        puts("arguments error.");
    }else if(argc==2){
        //统计标准输入的字符的出现次数
        puts("Plese input(enter to quit).");
        while(gets(strings)&&strings[0]!='\0'){
            int i;
            int count=0;
            for(i=0;strings[i]!='\0';i++){
                if(strings[i]==argv[1][0])
                    count++;
            }
            fprintf(stdout,"The number of %c in stdin is %d.\n",
                    argv[1][0],count);
        puts("Plese input(enter to quit).");
        }
    }else {
    //打开文件，统计字符出现次数
    int i;
    for(i=2;i<argc;i++){
        if((fp=fopen(argv[i],"r"))==NULL){
            fprintf(stderr,"Can't open %s.\n",argv[i]);
            continue;
        }else{
            tongji(fp,argv[1][0],argv[i]);
            fclose(fp);
        }
    }
    }
    return 0;
}
void tongji(FILE *fp,char ch,char* name)
{
    char x;
    int count=0;
    while((x=getc(fp))!=EOF){
        if(x==ch){
            count++;
        }
    }
    fprintf(stdout,"The number of %c in %s is %d.\n",ch,name,count);
}
