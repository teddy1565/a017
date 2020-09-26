#include<stdio.h>
#include<stdlib.h>
typedef char string[1000];
const int strLen=1000;
int calcu(char model,int num_1,int num_2){
    switch(model){
        case '+':
            return num_1+num_2;
        case '-':
            return num_1-num_2;
        case '*':
            return num_1*num_2;
        case '/':
            return num_1/num_2;
        case '%':
            return num_1%num_2;
        default:
            break;
    }
    return 0;
}
int check_operator(char c){
    if(c=='+'||c=='-'||c=='/'||c=='*'||c=='%')return 1;
    return 0;
}
int expr(string str,int str_p){
    while(str[str_p]!='\n'&&str[str_p]!='\0'&&str[str_p]!='('&&str[str_p]!=')'){
        if(str[str_p]=='+'||str[str_p]=='-')return 1;
        str_p++;
    }
    return 0;
}
int parser(string str,int str_p){
    string num;
    string parser_L;
    for(int i=0;i<strLen;i++){
        num[i]='\0';
        parser_L[i]='\0';
    }
    for(int i=str_p,brack_count=0;str[i]!='\n'&&str[i]!='\0';i++){
        if(str[i+1]=='\n'||str[i+1]=='\0'){
            while(brack_count!=0){
                if(str[str_p]==')')brack_count--;
                str_p++;
            }
            break;
        }
        if(str[i]=='(')brack_count++;
    }
    
    num[0]='+';
    if(str[0]=='-')num[0]='-';
    
    if(expr(str,str_p+1)==1){
        for(int k=0;str[str_p]!='\n'&&str[str_p]!='\0';str_p++){
            if(str[str_p]==' ')continue;
            if(str[str_p]=='+'||str[str_p]=='-')return calcu(str[str_p],parser(parser_L,0),parser(str,str_p+1));
            parser_L[k] = str[str_p];k++;
        }
    }else{
        for(int k=1;str[str_p]!='\0'&&str[str_p]!='\n';str_p++){
            if(str[str_p]==' ')continue;
            if(check_operator(str[str_p])==1)return calcu(str[str_p],atoi(num),parser(str,str_p+1));
            num[k]=str[str_p];k++;
        }
    }
    return atoi(num);
}

int main(){
    while(1){
        string keyin;
        fgets(keyin,strLen,stdin);
        if(keyin[0]=='\n'||keyin[0]=='\0')break;
        int ans = parser(keyin,0);
        printf("%d\n",ans);
    }
    return 0;
}