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
        if(str[str_p]=='+'||str[str_p]=='-')return 1;
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
    }
    num[0]='+';
    //parse negative number
    if(str[0]=='-')num[0]='-';
    //parse brack
    
    //calculation
    if(expr(str,str_p+1)==1){
        for(int k=0;str[str_p]!='\n'&&str[str_p]!='\0';str_p++){
            if(str[str_p]==' ')continue;
            else if(str[str_p]=='+'||str[str_p]=='-')return calcu(str[str_p],parser(expr_string,0),parser(str,str_p+1));
            expr_string[k] = str[str_p];k++;
        }
    }else{
        for(int k=1,counter=0;str[str_p]!='\n'&&str[str_p]!='\0';str_p++){
            if(str[str_p]==' ')continue;
            if(str[str_p]=='('){
                str_p++;
                counter++;
            }
            for(int s=0;counter!=0;s++,str_p++){
                brack_string[s]=str[str_p];
                if(str[str_p]==')'){
                    counter--;
                    if(counter==0){
                        for(int ak=str_p+1;str[ak]!='\n'&&str[ak]!='\0';ak++){
                            if(check_operator(str[ak])==1)return calcu(str[ak],parser(brack_string,0),parser(str,ak+1));
                        }
                    }
                }
            }
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