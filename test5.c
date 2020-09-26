#include<stdio.h>
void EX(char &str){
  *str[0]='f';
}
int main(){
  char string[1000];
  //char save[1000];
  EX(&string);
  printf("%s",string);
  return 0;
}