#include<stdio.h>
char *exange(char *str){
  int i=0;
  char *str_change[1000];
  while(str[i]!='\0'){
    *str_change[i] = str[i];
    str[i]='0';
    
  }
  printf("%s",*str_change);
  return *str_change;
}
int main(){
  char *str;
  char a[1000];
  for(int i=0;i<1000;i++){
    a[i]='1';
  }
  *str = *exange(a);
  return 0;
}