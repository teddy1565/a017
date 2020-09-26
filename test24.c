#include<stdio.h>
int check_num(char n){
    switch(n){
        case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
            return 1;
        default:
            return 0;
    }
    return 0;
}
int main(){
    printf("%d",check_num('f'));
    return 0;
}