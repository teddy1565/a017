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
int parser(string str,int str_p){
    int num=0,sum=0,N_string_p=1;
    string N_string;
    N_string[0]='+';
    char operator=' ',next_operator=' ';
    while(1){
        if(str[str_p]=='\0'||str[str_p]=='\n')break;
        if(str[str_p+1]=='\0'||str[str_p+1]=='\n')return atoi(N_string);
        if(str[str_p]=='('){
            parser(str,str_p+1);
        }else if(str[str_p]==')'){
            return sum;
        }
        
        if(str[str_p]!=' '&&check_operator(str[str_p])==0){//parsing integer
            N_string[N_string_p]=str[str_p];
            N_string_p++;
            str_p++;
            sum = atoi(N_string);
            continue;
        }else if(check_operator(str[str_p])==1&&check_operator(str[str_p+1])==0&&str[str_p+1]!=' '){
            N_string[0]='-';
            str_p++;
            sum = atoi(N_string);
            continue;
        }
        if(check_operator(str[str_p])==1){
            if(str[str_p]=='+'||str[str_p]=='-'){
                sum = calcu(str[str_p],atoi(N_string),parser(str,str_p+1));
                N_string[0]='+';
                for(int N_string_k=1;N_string_k<strLen;N_string_k++){
                    N_string[N_string_k]='\0';
                }
            }else{
                num=atoi(N_string);
                N_string[0]='+';
                for(int k=1;k<strLen;k++){
                    N_string[k]='\0';
                }
                for(int k=str_p+1;str[k]!='\n'&&str[k]!='\0';k++){
                    if(check_operator(str[k])==1){
                        operator=str[k];
                        break;
                    }
                }
                if(operator=='*'||operator=='/'||operator=='%'){
                    sum = calcu(str[str_p],atoi(N_string),parser(str,str_p+1));
                }else{
                    num = atoi(N_string);
                    for(int k=str_p+1,N_string_i=1;str[k]!='\0'&&str[k]!='\n';k++){
                        if(check_operator(str[k])==0&&str[k]!=' '){
                            N_string[N_string_i] = str[k];
                            N_string_i++;
                        }else if(check_operator(str[k])==1){
                            str_p=k;
                            break;
                        }
                    }
                    sum = calcu(operator,calcu(str[str_p],num,atoi(N_string)),parser(str,str_p+1));
                }
            }
        }
        str_p++;
    }
    return sum;
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