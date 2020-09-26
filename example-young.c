#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char string[1000];
const int strLen=1000;
int calcu(char c,int a,int b){
    switch(c){
        case '+':
            return a+b;
        case '-':
            return a+b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '%':
            return a%b;
        default:
            return 0;
    }
    return 0;
}
int parser(string data,int i){
    string Left_string;
    string Right_string;
    memset(Left_string,'\0',strLen);
    memset(Right_string,'\0',strLen);
    for(int j=i,k=0;data[j]!='\n'&&data[j]!='\0';j++){
        if(data[j]=='+'||data[j]=='-'){
            for(int s = j+1,m=0;data[s]!='\n'&&data[s]!='\0';s++,m++){
                Right_string[m]=data[s];
            }
            return calcu(data[j],parser(Left_string,i),parser(Right_string,0));
        }
        Left_string[k] = data[j];k++;
    }
    memset(Left_string,'\0',strLen);
    memset(Right_string,'\0',strLen);
    for(int l=i,m=0;data[l]!='\n'&&data[l]!='\0';l++){
        if(data[l]=='*'||data[l]=='/'||data[l]=='%'){
            for(int s = l+1,r=0;data[s]!='\n'&&data[s]!='\0';s++,r++){
                Right_string[r] = data[s];
            }
            return calcu(data[l],atoi(Left_string),parser(Right_string,0));
        }
        Left_string[m]=data[l];m++;
    }
    memset(Left_string,'\0',strLen);
    for(int j=i,k=0;data[j]!='\n'&&data[j]!='\0';j++,k++){
        Left_string[k]=data[j];
    }
    return atoi(Left_string);
}
int main(){
    string data;
    string filter;
    memset(filter,'\0',strLen);
    memset(data,'\0',strLen);
    fgets(data,strLen,stdin);
    for(int i=0,j=0;i<strLen;i++){
        if(data[i]==' ')continue;
        else if(data[i]=='\0'||data[i]=='\n'){
            printf("ans:%d\n",parser(filter,0));
            break;
        }
        filter[j] = data[i];j++;
    }
    return 0;
}