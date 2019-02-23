#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROWS 20
#define COLS 30
int main(int argc,char * argv[])
{
    int num[ROWS][COLS];
    int i,j;
    //创建文件
    FILE* fp;
    if((fp=fopen("input","w"))==NULL){
        puts("Can't creat file input.");
        exit(1);
    }
    for(i=0;i<ROWS;i++){
        //srand(time(NULL));
        for(j=0;j<COLS;j++){
            if(j==COLS-1){
                fprintf(fp,"%d\n",rand()%9);
            }else {
                fprintf(fp,"%d ",rand()%9);
            }

        }

    }
    if(fclose(fp)){
        puts("file closed failed.");
        exit(2);
    }

    //读取文件
    if((fp=fopen("input","r"))==NULL){
        puts("file input open failed.");
        exit(3);
    }
   // else
     //   puts("file open successed.");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            fscanf(fp,"%d",&num[i][j]);
       //     if(j==COLS-1)
         //       printf("%d\n",num[i][j]);
         // else
        //   printf("%d ",num[i][j]);
        }
    }

    //0-9的对应字符串表
    char *strings=" .,:~*=$%#";
    puts(strings);

    //图片字符串
    char picture[ROWS][COLS+1];
    memset(picture,'\0',(COLS+1)*ROWS);

     if((fp=fopen("output","w"))==NULL){
        puts("Can't create output.");
        exit(4);
    }
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            int x=num[i][j];
            picture[i][j]=strings[x];

        }
        fputs(picture[i],stdout);

        putchar('\n');
        fputs(picture[i],fp);
        putc('\n',fp);

    }

    return 0;
}
