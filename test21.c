#include<stdio.h>
typedef char string[1000];
int main(){
    string keyin;
    while(1){
        printf("%s\n",fgets(keyin,1000,stdin));
    }
    return 0;
}