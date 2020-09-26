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
    string num;
    num[0]='+';
    int sum=0;
    //find first integer and first operator
    for(int x=1;str[str_p]!='\0'&&str[str_p]!='\n';str_p++){
        if(str[str_p+1]==' '&&str[str_p-1]==' ')break;
        if(str[str_p]=='-')num[0]='-';
        else if(check_operator(str[str_p])==0&&str[str_p]!=' '){
            num[x] = str[str_p];
            x++;
        }
    }
    sum = atoi(num);
    for(int i=1;i<strLen;i++){
        num[i]='\0';
    }
    num[0]='+';

    for(int i=1;str[str_p]!='\n'&&str[str_p]!='\0';str_p++){
        if(str[str_p]=='+'||str[str_p]=='-'){
            sum = calcu(str[str_p],sum,parser(str,str_p+1));
        }
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