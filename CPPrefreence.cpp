#include<iostream>
#include<stack>
using namespace std;
int priv[300];
int value[300];
int calc(int a,int b,char op){
    if(op=='+')return a+b;
    if(op=='-')return a-b;
    if(op=='*')return a*b;
    if(op=='/')return a/b;
    if(op=='%')return a%b;
}
int calculate(string str,int val[]=value){
    stack <int> num;
    stack <char> oper;
    priv['+'] = priv['-'] = 3;
    priv['*'] = priv['/'] = 2;
    priv['%'] = 1,priv['('] = 10;
    int x,y,t=0;
    int i;char last =0;
    for(i=0;i<str.length();i++){
        if(isalpha(str[i])){
            num.push(val[str[i]]);
        }else if(isdigit(str[i])){
            num.push(atof(str.c_str()+i));
            for(;i+1<str.length()&&isdigit(str[i+1]);i++);
        }else if(str[i]=='('){
            oper.push(str[i]);
        }else if(str[i]==')'){
            while(oper.top()!='('){
                y=num.top();num.pop();
                x=num.top();num.pop();
                char op = oper.top();
                num.push(calc(x,y,op));
            }
            oper.pop();
        }else if(str[i]=='-'&&(last==0||last=='(')){
            num.push(0);
            oper.push('-');
        }else if(priv[str[i]]>0){
            while(oper.size()>0&&priv[str[i]]>=priv[oper.top()]){
                y = num.top();num.pop();
                x = num.top();num.pop();
                char op = oper.top();
                oper.pop();
                num.push(calc(x,y,op));
            }
            oper.push(str[i]);
        }else continue;
        last = str[i];
    }
    while(oper.size()>0){
        y=num.top();num.pop();
        x=num.top();num.pop();
        char op = oper.top();
        oper.pop();
        num.push(calc(x,y,op));
    }
    return num.top();
}
int main(){
    string str;
    while(cin >> str){
        
        cout << calculate(str);
    }
    return 0;
}