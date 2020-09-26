#include<stdio.h>
typedef char string[1000];
char *clear(char *str){
  return &(str[0]);
}
int main(){
  string str;
  scanf("%s",str);
  &(str[0]) = *clear(str);
  //printf("%d",*clear(str));
  return 0;

}