#include<stdio.h>
#include<stdlib.h>
typedef char string[1000];
const int strLen = 1000;
int parser(string str,int str_p);
int mul(string str,int str_p);
int term(string str,int str_p);
int last_brack(string str,int str_p);
int calcu(char operator,int a,int b){
    switch(operator){
        case '+':
            return a+b;
        case '-':
            return a+b;
        case '*':
            return a+b;
        case '/':
            return a+b;
        case '%':
            return a+b;
        default:
            return 0;
    }
    return 0;
}
int check_num(char num){
    switch(num){
        case ('0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9'):
            return 1;
        default:
            return 0;
    }
    return 0;
}
int last_mul_operator(string str,int str_p,int operator){
    while(str[str_p]!='\n'&&str[str_p]!='\0'){
        if(str[str_p]=='*'||str[str_p]=='/'||str[str_p]=='%')return last_mul_operator(str,str_p+1,str_p);
        else if(str[str_p]=='('){
            break;
        }
        str_p++;
    }
    return operator;
}
int check_operator(string str,int str_p){
    if(str[str_p+1]==' '&&str[str_p+1]==' '){
        if(str[str_p]=='+'||str[str_p]=='-'||str[str_p]=='*'||str[str_p]=='/'||str[str_p]=='%')return 1;
    }
    return 0;
}
int last_brack(string str,int str_p){
    while(str[str_p]!='\n'&&str[str_p]!='\0'){
        if(str[str_p]=='(')return last_brack(str,str_p+1);
        else if(str[str_p]==')')return str_p+1;
        str_p++;
    }
    return str_p;
}
int last_expr_operator(string str,int str_p,int operator){
    while(str[str_p]!='\n'&&str[str_p]!='\0'){
        if(str[str_p]=='(')str_p = last_brack(str,str_p+1);
        else if((str[str_p]=='+'||str[str_p]=='-')&&check_operator(str,str_p)==1)return last_expr_operator(str,str_p+1,str_p);
        str_p++;
    }
    return operator;
}
int expr(string str,int str_p){
    int expr_p = last_expr_operator(str,str_p,0);
    if(expr_p==0)return mul(str,str_p);
    string L_string;
    for(int i=0;i<strLen;i++){
        L_string[i]='\0';
    }
    for(int i=0;str_p<expr_p&&str[str_p]!='\n'&&str[str_p]!='\0';i++,str_p++){
        L_string[i] = str[str_p];
    }
    return calcu(str[expr_p],parser(L_string,0),parser(str,expr_p+1));
}
int mul(string str,int str_p){
    string num;
    for(int k=0;k<strLen;k++){
        num[k]='\0';
    }
    int mul_sum=0;
    int mul_p = last_mul_operator(str,str_p,0);
    if(mul_p==0)return term(str,str_p);
    for(int i=0;i<mul_p;i++,str_p++){
        if(str[str_p]==' ')continue;
        if(str[str_p]=='*'||str[str_p]=='/'||str[str_p]=='%'){
            
            return calcu(str[str_p],atoi(num),parser(str,str_p+1));
        }
        num[i] = str[str_p];
    }
    return calcu(str[mul_p],atoi(num),term(str,mul_p+1));
}
int term(string str,int str_p){
    string parse;
    for(int i=0;i<strLen;i++){
        parse[i]='\0';
    }
    for(int i=0;str[str_p]!='\n'&&str[str_p]!='\0';i++,str_p++){
        if(str[str_p]=='('){
            int term_p = last_brack(str,str_p);
            while(str[term_p]!='\n'&&str[term_p]!='\0'){
                if(check_operator(str,term_p)==1)return calcu(str[term_p],term(str,str_p+1),expr(str,term_p+1));
                term_p++;
            }
            return term(str,str_p+1);
        }else if(str[str_p]==')'){
            str_p++;
            return expr(parse,0);
        }
        
        parse[i] = str[str_p];
    }
    return parser(parse,0);
}
int parser(string str,int str_p){
    string num;
    for(int i=0;i<strLen;i++){
        num[i]='\0';
    }
    for(int i=str_p;str[i]!='\0'&&str[i]!='\n';i++){
        if(str[i]=='(')i = last_brack(str,i);
        if(str[i]=='+'||str[i]=='-'){
            return expr(str,str_p);
        }
    }
    for(int i=str_p;str[i]!='\0'&&str[i]!='\n';i++){
        if(str[i]=='(')i = last_brack(str,i);
        if(str[i]=='*'||str[i]=='/'||str[i]=='%'){
            return mul(str,str_p);
        }
    }
    for(int i=0;str[str_p]!='\0'&&str[str_p]!='\n';str_p++){
        if(str[str_p]==' ')continue;
        num[i] = str[str_p];i++;
    }
    return atoi(num);
}
int main(){
    string Keyin;
    while(fgets(Keyin,strLen,stdin)!=NULL){
        printf("%d\n",parser(Keyin,0));
    }
    return 0;
}