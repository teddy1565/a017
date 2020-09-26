#include<stdio.h>
#include<string.h>
/*
  輸入資料若干行直到 EOF 為止。每一行包含輸入一個字串，其中包含運算元及運算子，為了方便讀取，所有的運算子及運算元均以空格區隔。
  運算元為 0 ~231 -1 的整數
  運算子則包含 + - * / % 及 ( )
  運算時請注意先乘除後加減及() 優先運算的計算規則
*/
typedef char string[10000];
const string_length = 10000;
int ctoi(char c){
  switch(c){
    case '0':
      return 10;
      break;
    case '1':
      return 1;
      break;
    case '2':
      return 2;
      break;
    case '3':
      return 3;
      break;
    case '4':
      return 4;
      break;
    case '5':
      return 5;
      break;
    case '6':
      return 6;
      break;
    case '7':
      return 7;
      break;
    case '8':
      return 8;
      break;
    case '9':
      return 9;
      break;
    default:
      break;
  }
  return 0;
}
int check_EOF(char *str){
  int i=0;
  while(1){
    if(str[i]=='\n'||str[i]=='\0')break;
    i++;
  }
  return i;
}
char itoc(int n){
  switch(n){
    case 1:
      return '1';
      break;
    case 2:
      return '2';
      break;
    case 3:
      return '3';
      break;
    case 4:
      return '4';
      break;
    case 5:
      return '5';
      break;
    case 6:
      return '6';
      break;
    case 7:
      return '7';
      break;
    case 8:
      return '8';
      break;
    case 9:
      return '9';
      break;
    case 0:
      return '0';
      break;
    default:
      break;
  }
  return '0';
}
int parse(char *str,int i,int n){
  string result;
  int num[1000];
  for(int i=0;i<1000;i++){
    num[i]=0;
  }
  int op[100];
  for(int ls=0;ls<100;ls++){
    op[ls]=0;
  }
  int sum=0;
  int TS=0;
  int k=0;
  int crls_r=0;
  while(str[n]!='\n'&&str[n]!='\0'){//優先解決括弧
    if(k!=0){
      if(str[n]!='('&&str[n]!=')'&&str[n]!='+'&&str[n]!='-'&&str[n]!='*'&&str[n]!='/'&&str[n]!='%'&&str[n]!=' '){
        num[i] = num[i]*10+ctoi(str[n]);
      }else{
        /*
          1 --add
          2 --sub
          3 --mul
          4 --div
          5 --remainder
        */
        switch(str[n]){
          case '+':
            op[crls_r]=1;
            crls_r++;
            break;
          case '-':
            op[crls_r]=2;
            crls_r++;
            break;
          case '*':
            op[crls_r]=3;
            crls_r++;
            break;
          case '/':
            op[crls_r]=4;
            crls_r++;
            break;
          case '%':
            op[crls_r]=5;
            crls_r++;
            break;
          default:
            break;
        }
        i++;
      }
    }
    if(str[n]=='(')k=n;
    if(str[n]==')'){
      int _str_while_op_counter_1=0;
      int _str_while_num_counter_1=0;
      while(op[_str_while_op_counter_1]!=0){
        switch(op[_str_while_op_counter_1]){
          case 3:
            num[_str_while_num_counter_1] = num[_str_while_num_counter_1] * num[_str_while_num_counter_1+1];
            num[_str_while_num_counter_1+1] = 0;
            _str_while_num_counter_1+=2;
            break;
          case 4:
            break;
          default:
            _str_while_op_counter_1++;
            break;
        }
      }
    }
    n++;
  }
}
//clear memset('char array',0,index*sizeof(array[0]));
int main(){
  string input;
  string cpySTR1;

  while(1){
    if(check_EOF(input)==0)break;
    fgets(input,string_length,stdin);
    parse(input,0,0);
  }
  return 0;
}