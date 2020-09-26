#include<stdio.h>
int main(){
    char st[5];
    scanf("%s",st);
    printf("%d",st[0]==('+'&'-'));
    return 0;
}