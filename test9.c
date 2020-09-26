#include<stdio.h>
typedef char string[1000];
int get_st(char *str,int i){
  char *p = &str[i];
  printf("%c",*p);
  return 0;
}
int main(){
  string str;
  scanf("%s",str);
  get_st(str,0);
  return 0;
}