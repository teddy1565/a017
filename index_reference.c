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
    while(str[str_p]!='\n'&&str[str_p]!='\0'&&str[str_p]!='('&&str[str_p]!=')'){
        if(str[str_p]=='+'||str[str_p]=='-'){
            if(str[str_p+1]==' '&&str[str_p-1]==' ')return 1;
        }
        str_p++;
    }
    return 0;
}

int parser(string str,int str_p){
    string num;
    string brack_string;
    string expr_string;
    for(int i=0;i<strLen;i++){
        num[i]='\0';
        brack_string[i]='\0';
        expr_string[i]='\0';
    }
    num[0]='+';
    //parse negative number
    if(str[0]=='-')num[0]='-';
    //parse brack
    //Left brack always at string title
    
    //calculation
    if(expr(str,str_p)==1){
        for(int k=0;str[str_p]!='\n'&&str[str_p]!='\0';str_p++){
            if(str[str_p]==' ')continue;
            else if((str[str_p]=='+'||str[str_p]=='-')&&str[str_p+1]==' '&&str[str_p-1]==' '){
                if(expr(str,str_p+1)==0)return calcu(str[str_p],parser(expr_string,0),parser(str,str_p+1));
            }
            expr_string[k] = str[str_p];k++;
        }
    }else{
        for(int k=1,counter=0;str[str_p]!='\n'&&str[str_p]!='\0';str_p++){
            if(str[str_p]=='('){
                str_p++;
                int counter=1;
                for(int counter=1,lm=0;str[str_p]!='\0'&&str[str_p]!='\n';str_p++){
                    if(str[str_p]=='(')counter++;
                    else if(str[str_p]==')')counter--;
                    if(counter==0)break;
                    brack_string[lm]=str[str_p];lm++;
                }
                str_p++;
                while(str[str_p]!='\0'&&str[str_p]!='\n'){
                    if(check_operator(str[str_p])==1)return calcu(str[str_p],parser(brack_string,0),parser(str,str_p+1));
                    str_p++;
                }
                return parser(brack_string,0);
            }
            if(str[str_p]==' ')continue;
            else if(check_operator(str[str_p])==1)return calcu(str[str_p],atoi(num),parser(str,str_p+1));
            num[k]=str[str_p];k++;
        }
    }
    return atoi(num);
}
int main(){
    string keyin;
    while(fgets(keyin,strLen,stdin)!=NULL){
        int ans = parser(keyin,0);
        printf("%d\n",ans);
    }
    return 0;
}