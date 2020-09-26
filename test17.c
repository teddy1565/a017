#include<stdio.h>
#include<stdlib.h>
int main(){
    char num[100];
    for(int i=1;i<8;i++){
        num[i]='1';
    }
    num[0]='+';
    printf("%d",atoi(num));
    return 0;
}