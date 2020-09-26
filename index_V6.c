#include<stdio.h>
typedef char string[1000];
const int strLen=1000;
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
int filter_regex(char c){
    if(c==' '||c=='+'||c=='-'||c=='/'||c=='*'||c=='%')return 1;
    return 0;
}
int compare(char a,char b){//0.a==b 1.a>b 2.a<b
    if(a=='*'||a=='/'||a=='%'){
        if(b=='+'||b=='-'){
            return 1;
        }
    }else{
        if(b=='*'||b=='/'||b=='%'){
            return 2;
        }
    }
    return 0;
}
void parse(string str,int str_true_length,int model){
    int bracket_num_arr[1000];
    int sum=0,num=0;
    char operator=' ',next_operator=' ';
    int L_brack_array[1000];
    int R_brack_array[1000];
    for(int i=0,j=0,k=0,brack_counter=0;i<=str_true_length;i++){
        if(i==str_true_length){
            for(int brack_calcu_i=0,brack_calcu_num_array_index=0;brack_calcu_i<brack_counter;brack_calcu_i++){
                int p=L_brack_array[(brack_counter-1)-brack_calcu_i]+1;
                int end = R_brack_array[brack_calcu_i]+1;
                int brack_calcu_num=0;
                int brack_calcu_sum=0;
                char brack_calcu_operator=' ';
                char brack_next_calcu_operator=' ';
                while(p!=end){
                    if(str[p]=='('||str[p]==')'){
                        p++;
                        continue;
                    }//
                    if(str[p]!=' '){
                        if(filter_regex(str[p])==1){
                            if(brack_calcu_operator==' '){
                                brack_calcu_sum=brack_calcu_num;
                                brack_calcu_operator = str[p];
                                brack_calcu_num=0;
                            }else{
                                switch(compare(brack_calcu_operator,str[p])){
                                    case 0://若下一個運算子優先程度等於原本紀錄的運算子
                                        brack_calcu_sum = calcu(brack_calcu_operator,brack_calcu_sum,brack_calcu_num);
                                        brack_calcu_operator = str[p];
                                        brack_calcu_num = 0;
                                        break;
                                    case 1://若下一個運算子優先程度小於原本紀錄的運算子
                                        brack_calcu_sum = calcu(brack_calcu_operator,brack_calcu_sum,brack_calcu_num);
                                        brack_calcu_operator = str[p];
                                        brack_calcu_num = 0;
                                        break;
                                    case 2://若下一個運算子大於原本紀錄的運算子
                                        next_operator=str[p];
                                        for(int brack_calcu_district=0,brack_calcu_dis_j=brack_calcu_num;str[p]!='\0'&&str[p]!='\n';p++){
                                            if(str[p]==' '){
                                                continue;
                                            }else if(filter_regex(str[p])==1&&str[p]!=' '){
                                                //brack_calcu_sum = calcu(next_operator,brack_calcu_sum,brack_calcu_num);
                                                p--;
                                                break;
                                            }
                                            brack_calcu_district = brack_calcu_district*10+ctoi(str[p]);
                                            brack_calcu_num = calcu(next_operator,brack_calcu_dis_j,brack_calcu_district);
                                        }
                                    default:
                                        break;
                                }
                            }
                        }else{
                            brack_calcu_num = brack_calcu_num*10+ctoi(str[p]);
                        }
                    }
                    p++;
                }
            }
            break;
        }
        if(str[i]=='('){
            L_brack_array[j]=i;
            j++;
            L_brack_array[j]=-404;
            brack_counter++;
        }else if(str[i]==')'){
            R_brack_array[k]=i;
            k++;
            R_brack_array[k]=-404;
            brack_counter++;
        }
    }
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