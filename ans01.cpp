#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
int DFS(int,int);
string s;
int main(){
  while(getline(cin,s)){
    int result=DFS(0,s.length());
    cout << result<<endl; 
  } 
}
int DFS(int le,int ri){
  int c=0;
  for(int i=ri-1;i>=le;i--){//後加減，先遞迴 
    if (s[i]==')') c++;    //括弧內部分割      
    if (s[i]=='(') c--;
    if (s[i]=='+' && c==0){ //後加減，先遞迴 
      return DFS(le,i)+DFS(i+1,ri);
    }
    if (s[i]=='-' && c==0){
      return DFS(le,i)-DFS(i+1,ri);
    }  
  }    
  for(int i=ri-1;i>=le;i--){ //先乘除，後遞迴 
    if (s[i]==')') c++;    //括弧內部分割      
    if (s[i]=='(') c--;
    if (s[i]=='*' && c==0){ //先乘除，後遞迴 
      return DFS(le,i)*DFS(i+1,ri);
    }
    if (s[i]=='/' && c==0){
      return DFS(le,i)/DFS(i+1,ri);
    }
    if (s[i]=='%' && c==0){
      return DFS(le,i)%DFS(i+1,ri);
    }         
  }    
  if ((s[le]=='(')&&(s[ri-1]==')')) return DFS(le+1,ri-1);  //去除刮號
  if (s[le]==' ' &&s[ri-1]==' ') return  DFS(le+1,ri-1); //去除左右兩邊空格 
  if (s[le]==' ') return  DFS(le+1,ri); //去除左邊空格 
  if (s[ri-1]==' ') return  DFS(le,ri-1); //去除右邊空格
  int num=0;
  if (isdigit(s[le])&&isdigit(s[ri-1])){//轉成數字 
    for(int i=le;i<ri;i++) num=num*10+s[i]-'0';
    return num;
  }
}