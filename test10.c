#include<stdio.h>
typedef char string[1000];
char *exchange(string *a){
  string *ram;
  for(int i=0;i<1000;i++){
    ram[i]=&a[i];
  }
  return *ram;
}
int main(){
  string a;
  string *b;
  *b = *exchange(&a);
  return 0;
}