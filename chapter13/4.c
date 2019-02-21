#include<stdio.h>
#include<stdlib.h>
void display(FILE *fp);
int main(int argc,char* argv[])
{
    if(argc<2){
        puts("No file to display.");
        exit(1);
    }
    int i=1;
    FILE *fp;
    for(;i<argc;i++){
        if((fp=fopen(argv[i],"r"))==NULL){
            fprintf(stderr,"Can't open %s.\n",argv[i]);
            exit(2);
        }else{
            display(fp);
            fclose(fp);
        }
    }
    return 0;
}

void display(FILE *fp)
{
    char ch;
    while((ch=getc(fp))!=EOF){
        putc(ch,stdout);
    }
}
