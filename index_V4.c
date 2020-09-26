#include<stdio.h>
typedef char string[1000];
const strLen = 1000;
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
int parse(string str,int strLen,int i){
    int num=0;
    string L;
    string R;
    while(str[i]!='\n'&&str[i]!='\0'){
        
        if(str[i]=='+'||str[i]=='-'){
            int ___str_L_counter = 0;
            while(num!=0){
                int ___num_p_counter = 1;
                while((num/___num_p_counter)>9){
                    ___num_p_counter*=10;
                }
                L[___str_L_counter] = itoc(num/___num_p_counter);
                num/=10;
                ___str_L_counter++;
                ___num_p_counter++;
            }
        }else if(str[i]=='*'||str[i]=='/'||str[i]=='%'){

        }else if(str[i]==' '){
            i++;
            continue;
        }else{
            num = num*10+(str[i]-'0');
        }
        i++;
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
        parse(keyin,str_true_length,0);
    }
    return 0;
}