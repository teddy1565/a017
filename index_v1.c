#include<stdio.h>
#include<math.h>
#include<string.h>
char *clear(char *str,int strLen){
  for(int i=0;i<strLen;i++){
    str[i] = ' ';
  }
  return str;
}
int ctoi(char c){
  switch(c){
    case '0':return 10;break;
    case '1':return 1;break;
    case '2':return 2;break;
    case '3':return 3;break;
    case '4':return 4;break;
    case '5':return 5;break;
    case '6':return 6;break;
    case '7':return 7;break;
    case '8':return 8;break;
    case '9':return 9;break;
    default:return 0;break;
  }
  return 0;
}
char *push(char *data,char *push_data){
  for(int i=0;i<10000;i++){
    if(data[i]=='\0'||data[i]=='\n'){
      for(int j=0;j<10000;j++){
        if(push_data[j]=='\n'||push_data[j]=='\0')break;
        data[i+j] = push_data[j];
      }
      break;
    }
  }
  return data;
}
int stoi(char *num_str){
  int i=0;
  int res=0;
  while(1){
    if(num_str[i]=='\0'||num_str[i]=='\n'||num_str[i]==' ')break;
    res = res*10+ctoi(num_str[i]);
    i++;
  }
  return res;
}
char *parse(char *str,char *cover_str,int p1,int p2,int cover_str_length){
  char RAM[1000];
  int res=0;
  for(int i=cover_str_length-1;i>0;i--){
    if(cover_str[i]=='*'||cover_str[i]=='/'||cover_str[i]=='%'){
      int j=1;
      while(1){
      if(cover_str[i+j]==' '||cover_str[i+j]=='+'||cover_str[i+j]=='-'||cover_str[i+j]!='*'||cover_str[i+j]!='/'||cover_str[i+j]!='%'||cover_str[i+j]!='\n'||cover_str[i+j]!='\0')break;
        RAM[j-1]=cover_str[i+j];
        j++;
      }
      res = stoi(RAM);
      j=1;
      strcpy(RAM,clear(RAM,1000));
      while(1){
      if(cover_str[i-j]==' '||cover_str[i-j]=='+'||cover_str[i-j]=='-'||cover_str[i-j]=='*'||cover_str[i-j]=='/'||cover_str[i-j]=='\n'||cover_str[i-j]=='\0')break;
        RAM[j-1]=cover_str[i-j];
        j++;
      }
      switch(cover_str[i]){
        case '*':
          res = res*stoi(RAM);
          break;
        case '/':
          res = stoi(RAM)/res;
          break;
        case '%':
          res = stoi(RAM)%res;
          break;
        default:break;
      }
      printf("%d",res);
      break;
    }
  }
  //printf("%d",res);
  return str;
}
char *step1(char *str,int strLen){
  char RAM[10000];
  for(int i=0,j=0,c=0,p1=0,p2=0;i<strLen;i++){
    switch(str[i]){
      case '(':c=1;p1=i;break;
      case ')':c=2;p2=i;break;
      default:break;
    }
    if(c==1){
      RAM[j] = str[i];
      j++;
    }else if(c==2){
      RAM[j] = str[i];
      c=0;
      strcpy(str,parse(str,RAM,p1,p2,j));
      j=0;
    }
  }
  return str;
}
int main(){
  while(1){
    char str[10000];
    char RAM1[10000];
    char RAM2[10000];
    fgets(str,10000,stdin);
    if(str[0]=='\0'||str[0]=='\n')break;
    int str_true_length;
    for(int i=0;i<10000;i++){ //get str true length
      if(str[i]=='\n'){
        str_true_length = i;
        break;
      }
    }
    //parse
    *step1(str,str_true_length);
  }
  return 0;
}