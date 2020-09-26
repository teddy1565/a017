#include<ctype.h>
#include<stdarg.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//標記種類
typedef enum{
  TK_RESERVED,//符號
  TK_NUM,//整數標記
  TK_EOF//代表輸入結束的標記
} TokenKind;
/*
  typedef enum{
    January,
    February,
    March,
    .....,
  }month;
    printf("隨意輸入1到5之間的一個數");
  scanf("%d",&mon);
 
  switch(mon){
      case January:
          printf("一月"); break;
      case February:
          printf("二月"); break;
      case March:
          printf("三月"); break;
      case April:
          printf("四月"); break;
      case May:
          printf("五月"); break;
      default:
          printf("要輸入1到5之間的數喔");
  }
*/

typedef struct Token Token;

struct Token{
  TokenKind kind; //標記的型態
  Token *next;  //下一個輸入標記
  int val;  //kind為TK_NUM時的數值
  char *str;  //標記文字列
};

//正在處理的標記
Token *token;

//處理錯誤的函數
//取和printf相同的引數
void error(char *fmt,...){
  va_list ap;
  va_start(ap,fmt);
  vfprintf(stderr,fmt,ap);
  fprintf(stderr,"\n");
  exit(1);
}

//下一個標記為符合預期的符號時 讀入一個標記並往下繼續
//return true else return false
bool consume(char op){
  if(token->kind != TK_RESERVED||token->str[0]!=op){
    return false;
  }
  token = token->next;
  return true;
}
//下一個標記為符合預期的符號時 讀入一個標記並往下繼續
//否則警告為錯誤
void expect(char op){
  if(token->kind!=TK_RESERVED||token->str[0]!=op){
    error("不是'%c'",op);
  }
  token=token->next;
}
//下一個標記為數值時 讀入一個標記並往下繼續 回傳該數值
//否則警告為錯誤
int expect_number(){
  if(token->kind!=TK_NUM){
    error("不是數值");
  }
  int val=token->val;
  token = token->next;
  return val;
}

bool at_eof(){
  return token->kind == TK_EOF;
}

//建立一個新的標記 連結到cur
Token *new_token(TokenKind kind,Token *cur,char *str){
  Token *tok = calloc(1,sizeof(Token));
  tok->kind = kind;
  tok->str = str;
  cur->next = tok;
  return tok;
}
//將輸入的文字列p作標記解析並回傳標記連結串列
Token *tokenize(char *p){
  Token head;
  head.next = NULL;
  Token *cur = &head;
  
  while(*p){
      //跳過空白符號
      if(isspace(*p)){
        p++;
        continue;
      }
      if(*p=='+'||*p=='-'){
        cur = new_token(TK_RESERVED,cur,p++);
        continue;
      }
      if(isdigit(*p)){
        cur = new_token(TK_NUM,cur,p);
        cur->val = strtol(p,&p,10);
        continue;
      }
      error("標記解析失敗");
  }
  new_token(TK_EOF,cur,p);
  return head.next;
}

int main(int argc,char **argv){
  if(argc != 2){
    error("引數數量錯誤");
    return 1;
  }
  
  //標記解析
  token = tokenize(argv[1]);
  return 0;
}