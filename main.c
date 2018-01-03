#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
extern int errno ;

int getfilecontent(char **buf,char filename[],int unset){
    FILE *fp = NULL;
    long lsize;
    //printf("%s \n",filename);
    fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("%s\n",strerror(errno));
        exit(0);
    }else{
        fseek(fp,0,SEEK_END);//获取文件大小
        lsize = ftell(fp);
        rewind(fp);
        buf = (char*) malloc(sizeof(char)*lsize);
        if(buf == NULL){
            printf("文件为空\n");
            exit(0);
        }else{
            // 读取文件内容保存到指针变量
            if(fread(buf,1,lsize,fp) != lsize){
                printf("读取失败\n");
                exit(0);
            }
        }
    }
    printf(buf);
    fclose(fp);
    if(unset == 1) memset(buf,0,sizeof(buf));
    return 0;
}

int main(){
    char *buf[]={0};
    char str[] = "abc";
    char user[30] = "fuck";
    char passwd[30] = "abcd123";
    char input[30] = {0};
    getfilecontent(&buf,"/Users/existence/Desktop/c语言学习/C语言学习/login.txt",1);
    
    scanf("%30s",&input);
    printf("%s == %s",input,user);
    if(strcmp(input,user)==0){
        printf("\n* 请输入密码: \n");
        scanf("%30s",&input);
        if(strcmp(input,passwd)==0){
            printf("登录成功");
            
            getfilecontent(&buf,"/Users/existence/Desktop/c语言学习/C语言学习/welcome_ui.txt",1);
        }else{
            printf("密码错误,请重新输入");
        }
    }else{
        printf("\n* 用户名不存在! \n");
    }
    
    return 0;
}
