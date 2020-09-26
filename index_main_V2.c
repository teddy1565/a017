#include<stdio.h>
#include<stdlib.h>
typedef char string[1000];
const int strLen=1000;
int parser(string str,int str_p);
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
    while(str[str_p]!='\n'&&str[str_p]!='\0'){
        if(str[str_p]=='+'||str[str_p]=='-')return 1;
        str_p++;
    }
    return 0;
}
int parser(string str,int str_p){
    string num;
    for(int i=0;i<strLen;i++){
        num[i]='\0';
    }
    num[0]='+';
    if(str[0]=='-')num[0]='-';
    if(expr(str,str_p+1)==1){
        
        for(int k=0;str[str_p]!='\n'&&str[str_p]!='\0';str_p++){
            if(str[str_p]==' ')continue;
            else if(str[str_p]=='+'||str[str_p]=='-')return calcu(str[str_p],atoi(num),parser(str,str_p+1));
            num[k] = str[str_p];k++;
        }
    }else{
        for(int k=1,brack_num=0;str[str_p]!='\0'&&str[str_p]!='\n';str_p++){
            if(str[str_p]==' ')continue;
            if(check_operator(str[str_p])==1)return calcu(str[str_p],atoi(num),parser(str,str_p+1));    
            num[k]=str[str_p];k++;
        }
    }
    return atoi(num);
}
int check_p_s(char c){
    if(c=='+'||c=='-')return 1;
    return 0;
}
int parse_str(string str,int str_p){
    string parser_string;
    string L_string;
    int brack_sum=0;
    char operator=' ';
    int brack_selector=0;
    for(int check=str_p;str[check]!='\n'&&str[check]!='\0';check++){
        if(str[check]=='('){
            brack_selector=1;
            break;
        }
        if(str[check]==')'){
            brack_selector=2;
            break;
        }
    }
    if(brack_selector==1){
        for(int i=str_p,j=0;str[i]!='\n'&&str[i]!='\0';i++,j++){
            if(check_operator(str[i])==1)operator = str[i];
            if(str[i]=='('){
                if(check_operator(operator)==1){
                    while(check_operator(L_string[j])==0)j--;
                    L_string[j]='\0';
                    brack_sum = calcu(operator,parser(L_string,0),parse_str(str,i+1));
                }
                else brack_sum = parse_str(str,i+1);
            }
            L_string[j]=str[i];
        }
    }else if(brack_selector==2){
        for(int i=str_p,j=0;str[i]!='\n'&&str[i]!='\0';i++,j++){
            if(str[i]==')'){
                while(check_operator(str[i])==0&&str[i+1]!='\n'&&str[i+1]!='\0')i++;
                if(check_operator(str[i])==0)str_p=i;
                return parser(parser_string,0);
            }
            parser_string[j]=str[i];
        }
    }
    int brack_counttt=0;
    for(int i=str_p;str[i]!='\n'&&str[i]!='\0';i++){
        if(str[i]=='(')brack_counttt++;
    }
    while(brack_counttt>0){
        if(str[str_p]==')'){
            str_p++;
            brack_counttt--;
        }
        str_p++;
    }

    return 0;
}
int main(){
    while(1){
        string keyin;
        fgets(keyin,strLen,stdin);
        if(keyin[0]=='\n'||keyin[0]=='\0')break;
        int ans = parse_str(keyin,0);
        printf("%d\n",ans);
    }
    return 0;
}