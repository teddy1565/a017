#include<stdio.h>
#include<string.h>
typedef char string[1000];
char *strProc(char *str){
  str[0]='h';
  return str;
}
int main(){
  string str;
  string stp;
  //char stt[10000];
  strcpy(stp,strProc(str));
  return 0;
}