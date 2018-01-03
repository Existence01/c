#include <stdio.h>
#include <string.h>

int getfilecontent(char **buf,char filename[]){
    printf(filename);
    printf(buf);
    //buf = "爱仕达萨达";
    strcpy(buf,"爱仕达萨达");
    return 0;
}

int main(){
    printf("00000000\n");
    char buf[255]={0};
    char str[] = "abc";
    char user[30] = "fuck";
    char passwd[30] = "abcd123";
    FILE *fp = NULL;
    strcpy(buf, "安师大");
    memset( &buf, 0, sizeof(buf) );
    char f[] = "./welcome_ui.txt";
    getfilecontent(&buf,"./welcome_ui.txt");
    //exit(0);
    //getch();//等待终端输入任意字符
    printf(buf);
    exit(0);//退出程序
    printf(
           "************请登录**************\
           \n* 你需要进行py方可进入系统\
           \n*\
           \n* 请输入用户名: \n");
    scanf("%30s",&buf);
    if(strcmp(buf,user)==0){
        printf("\n* 请输入密码: \n");
        scanf("%30s",&buf);
        if(strcmp(buf,passwd)==0){
            printf("登录成功");
            fp = fopen("welcome_ui.txt", "rb");
            fgets(buf, 255, (FILE*)fp);
            fclose(fp);
        }else{
            printf("密码错误,请重新输入");
        }
    }else{
        printf("\n* 用户名不存在! \n");
    }
    
    return 0;
}
