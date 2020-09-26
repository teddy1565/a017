#include<stdio.h>
typedef char string[1000];
const string_Length = 1000;
int main(){
    string input;
    while(1){
        fgets(input,string_Length,stdin);
        if(input[0]=='\0'||input[0]=='\n')break;
        
    }
    return 0;
}