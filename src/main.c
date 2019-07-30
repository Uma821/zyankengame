//じゃんけんゲーム1.1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int hanbetu(char []);

int main(){
  char aite[256],humhand[256],comhand[256];
  int hantei,human,com;

  do{
    puts("ジャンケンをします。\nグー…1 チョキ…2 パー…3");
    gets(aite);
    hantei = hanbetu(aite);
  }while(hantei != 0);
  human = atoi(aite);

  if(human==1)
    strcpy(humhand,"グー");
  else if(human==2)
    strcpy(humhand,"チョキ");
  else
    strcpy(humhand,"パー");
  printf("%s\n",humhand);

  srand(time(NULL));
  com = rand()%3 + 1;
  if(com==1)
    strcpy(comhand,"グー");
  else if(com==2)
    strcpy(comhand,"チョキ");
  else
    strcpy(comhand,"パー");

  if(human==com)
    printf("コンピューターは%s\nあいこです\n",comhand);
  else if((human-com==2)||(com-human==1))
    printf("コンピューターは%s\nあなたの勝ちです\n",comhand);
  else
    printf("コンピューターは%s\nコンピューターの勝ちです\n",comhand);
  return 0;
}

int hanbetu(char moji[]){
  char *pp,nn='.',my='-';
  int mi=1,num=1;
  pp = moji;

  printf("%sは",pp);
  while((*pp!='\0')&&(*pp>='0'&&*pp<='9')){
    pp++;
    mi++;
    num++;
  }
  if(*pp=='\0' && mi!=1){
    if(*(pp-1)>='1'&&*(pp-1)<='3'&&mi==2)
      return 0;
    puts("0か1~3以外の正の整数です\n1〜3の整数を入力してください\n");
    return 1;
  }
  else if(*pp==my && mi==1){
    pp++;
    while(*pp!='\0'&&((*pp>='0'&&*pp<='9')||*pp==nn)){
      pp++;
      mi++;
    }
    if(*pp=='\0'&&mi!=num){
      puts("負の数です\n1〜3の整数を入力してください\n");
      return 1;
    }
  }
  else if(*pp==nn){
    pp++;
    while((*pp!='\0')&&(*pp>='0'&&*pp<='9'))
      pp++;
    if(*pp=='\0'){
      puts("小数です\n1〜3の整数を入力してください\n");
      return 1;
    }
  }
  else if(mi==1 && *pp=='\0'){
    puts("んべつできません。\n1〜3の整数を入力してください\n");
    return 1;
  }
  puts("文字列です\n1〜3の整数を入力してください\n");
  return 1;
}