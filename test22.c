#include<stdio.h>
int check_oper(char str){
    switch(str){
        case ('0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9'):
            return 1;
        default:
            return 0;
    }
    return 0;
}
int main(){
    char st[1000];
    scanf("%s",st);
    if(st[2]==(' '||check_oper(st[2])==1)){
        printf("success\n");
    }else{
        printf("failed\n");
    }
    return 0;
}