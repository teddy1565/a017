#include<stdio.h>
typedef char string[1000];
const strLen=1000;
char itoc(int k){
    switch(k){
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            return '0';
    }
    return '0';
}
int ctoi(char c){
    switch(c){
        case '0':
            return 1;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':   
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        default:
            return 0;
            break;
    }
    return 0;
}

/*
    expr = mul ("+" mul | "-"mul)*
    mul  = term ("*" term | "/" term)*
    term = num | "(" expr ")"
*/
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
int parse(string s,int p){
    int num=0;
    int sum=0;
    int mul_num=0;
    int k=0;
    int A=0;
    char before;//只是為了不要讓編輯器報錯宣告的 不要使用
    char mul_before=' ';
    char expr_before=' ';
    int sum=0;
    /*分析字串規則*/
    while(s[p]!='\0'&&s[p]!='\n'){
        if(s[p]==' '){ //檢查目前是否為空格
            if(s[p+1]=='*'||s[p+1]=='/'||s[p+1]=='%'){
                if(mul_num!=0){
                    num = calcu(before,mul_num,num);
                }else
                before = s[p+1];
                mul_num=num;
                num=0;
                continue;
            }else if(s[p+1]=='+'||s[p+1]=='-'){
                if(before=='*'||before=='/'||before=='%'){
                    sum=calcu(before,mul_num,num);
                    mul_num=0;
                }else if(before=='+'||before=='-'){
                    sum=calcu(before,sum,num);
                }
                before = s[p+1]=='+'?'+':'-';
                num = 0;
            }
        }else{
            num = num*10+ctoi(s[p]);
        }
    }
    //若讀取到文件結束
    if(before=='*'||before=='/'||before=='%'){
        calcu(before,mul_num,num);
        mul_num=0;num=0;
    }else if(before=='+'||before=='-'){
        calcu(before,sum,num);
        num=0;
        sum=0;
    }
    return 0;
}
int main(){
    while(1){
        string keyin;
        fgets(keyin,strLen,stdin);
        if(keyin[0]=='\n'||keyin[0]=='\0')break;
        int str_true_length;
        for(int i=0;i<strLen;i++){
            if(keyin[i]=='\n'||keyin[i]=='\0'){
                str_true_length=i;
                break;
            }
        }
        
    }
    return 0;
}