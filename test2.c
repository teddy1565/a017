#include<stdio.h>

char *strp(char *str){
  printf("%s",str);
  return str;
}
int main(){
  char str[1000];
  scanf("%s",str);
  printf("%s",strp(str));
  return 0;
}