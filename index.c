#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char string[1000];
const int strLen=1000;
int cross_brack(string str,int str_p,int counter){
    while(str[str_p]!='\0'&&str[str_p]!='\n'){
        if(counter==0)return str_p;
        if(str[str_p]==')')return cross_brack(str,str_p-1,counter+1);
        else if(str[str_p]=='(')return cross_brack(str,str_p-1,counter-1);
        str_p--;
    }
    return str_p;
}
int calcu(char c,int a,int b){
    switch(c){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '%':
            return a%b;
    }
    return 0;
}
int check_num(char n){
    switch(n){
        case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
            return 1;
        default:
            return 0;
    }
    return 0;
}
int check_operator(char c){
    switch(c){
        case '+':case '-':
            return 1;
        case '*':case '/':case '%':
            return 2;
        default:
            return 0;
    }
    return 0;
}
int parser(string str,int str_p){
    string num;
    string Left_string;
    string Right_string;
    //先找+/-
    memset(num,'\0',strLen);
    memset(Left_string,'\0',strLen);//清除記憶體殘值 確保計算準確度
    memset(Right_string,'\0',strLen);
    for(int l=0,i=str_p,brack=0;str[i]!='\0'&&str[i]!='\n';i++){
        if(str[i]=='(')brack++;
        if(brack==0){
            if(str[i]=='+'){
                for(int s=0,m=i+1;str[m]!='\0'&&str[m]!='\n';m++,s++){
                    Right_string[s] = str[m];
                }
                
                return calcu(str[i],parser(Left_string,0),parser(Right_string,0));
            }else if(str[i]=='-'){
                if(check_operator(str[i-1])==0&&i-1>=0){
                    for(int s=0,m=i;str[m]!='\0'&&str[m]!='\n';m++,s++){
                        Right_string[s] = str[m];
                    }
                    return calcu('+',parser(Left_string,0),parser(Right_string,0));
                }
            }
        }else{
            if(str[i]==')')brack--;
        }
        Left_string[l]=str[i];l++;
    }
    //處理乘除
    memset(num,'\0',strLen);
    memset(Left_string,'\0',strLen);
    memset(Right_string,'\0',strLen);
    int operator=0;
    for(int i=str_p,m=0,brack=0;str[i]!='\n'&&str[i]!='\0';i++){
        if(str[i]=='(')brack++;
        if(brack==0){
            if(str[i]=='*'||str[i]=='/'||str[i]=='%'){
                operator=i;
            }
        }else{
            if(str[i]==')')brack--;
        }
    }
    if(operator!=0){
        for(int m=str_p,k=0;m<operator;m++,k++){
            Left_string[k] = str[m];
        }
        for(int p=operator+1,k=0;str[p]!='\n'&&str[p]!='\0';p++,k++){
            Right_string[k]=str[p];
        }
        return calcu(str[operator],parser(Left_string,0),parser(Right_string,0));
    }
    //處理括號
    memset(num,'\0',strLen);
    memset(Left_string,'\0',strLen);
    memset(Right_string,'\0',strLen);
    int b=0,native_n=0;
    if(str[0]=='-')native_n=1;
    for(int i=str_p,brack=0,m=0;str[i]!='\n'&&str[i]!='\0';i++){
        if(str[i]==')')brack--;
        if(brack!=0){
            Left_string[m] = str[i];m++;
        }
        if(str[i]=='('){
            brack++;
            b=1;
        }
    }
    if(b==1&&native_n==0)return parser(Left_string,0);
    else if(b==1&&native_n==1)return 0-parser(Left_string,0);
    //處理整數
    memset(num,'\0',strLen);
    memset(Left_string,'\0',strLen);
    memset(Right_string,'\0',strLen);
    for(int l=0,i=str_p;str[i]!='\n'&&str[i]!='\0';i++,l++){
        num[l] = str[i];
    }
    return atoi(num);
}
int main(){
    string keyin;
    string data;
    memset(keyin,'\0',strLen);
    memset(data,'\0',strLen);
    while(fgets(keyin,1000,stdin)){
        for(int i=0,j=0;i<strLen;i++){
            if(keyin[i]==' ')continue;
            else if(keyin[i]=='\n'||keyin[i]=='\0'){
                printf("%d\n",parser(data,0));
                break;
            }
            data[j] = keyin[i];j++;
        }
        memset(data,'\0',strLen);
    }
    return 0;
}