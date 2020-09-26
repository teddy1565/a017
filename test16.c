#include<stdlib.h>
#include<stdio.h>
typedef char string[1000];
int main(){
    string num_test;
    int num;
    for(int i=0;i<10;i++){
        num_test[i]='1';
    }
    num=atoi(num_test);
    printf("%d",num);
    return 0;
}