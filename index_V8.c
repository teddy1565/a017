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
    int start_num=0;
    char operator=' ';
    int L=0;
    int R=0;
    int sum=0;
    while(str[str_p]!='\n'&&str[str_p]!='\0'){
        if(str[str_p]==' ')continue;
        if(check_operator(str[str_p])==1){

        }
        
    }
    for(int i=1;i<strLen;str_p++){
        if(str[str_p]==' ')continue;
        if(check_operator(str[str_p])==1&&check_operator(str[str_p+1])==0&&check_operator(str[str_p-1])==1){
            start_num = atoi(num);
            for(int k=0;k<strLen;k++){
                num[k]='\0';
            }
            num[0]='+';
            break;
        }
        num[i]=str[str_p];
    }
    for(int i=1;str[str_p]!='\0'&&str[str_p]!='\n';str_p++){
        if(check_operator(str[str_p])==0&&str[str_p]!=' '){
            num[i]=str[str_p];
        }else if(check_operator(str[str_p])==1){
            if(str[str_p]=='+'||str[str_p]=='-'){
                
            }else if(str[str_p]=='*'||str[str_p]=='/'||str[str_p]=='%'){
                //mul_n = atoi(num);
                for(int j=1;j<strLen;j++){
                    num[j]='\0';
                }
                num[0]='+';
            }
        }
    }
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