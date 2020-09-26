#include<stdio.h>
char change(char *str){
    int i=0;
    while(str[i]!='\n'&&str[i]!='\0'){
        str[i]='1';
        i++;
    }
    return *str;
}
int main(){
    char str[1000];
    for(int i=0;i<1000;i++){
        str[i]='0';
    }
    char *save[1000];
    *save = change(str);
    printf("%s\n",save);
    return 0;
}