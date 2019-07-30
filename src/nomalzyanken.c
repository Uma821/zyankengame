//じゃんけんゲーム1.4.2
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
    fflush(stdout);
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
  printf("は%s\n",humhand);

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
  char *pp, nn='.', my='-';
  int mi=1, num=1;
  pp = moji;

  printf("「%s」",pp);
  while((*pp!='\0')&&(*pp>='0'&&*pp<='9')){
    pp++;
    mi++;
    num++;
  }

  if(*pp=='\0' && mi!=1){
    if(atoi(moji)>=1 && atoi(moji)<=3)
      goto finish;
    puts("は0か1～3以外の正の整数です\n1～3の整数を入力してください\n");
    goto end;
  }

  else if(*pp==my && mi==1){
    pp++;
    while(*pp!='\0'&&((*pp>='0'&&*pp<='9')||*pp==nn)){
      pp++;
      mi++;
    }
    if(*pp=='\0' && mi!=num){
      puts("は負の数です\n1～3の整数を入力してください\n");
      goto end;
    }
  }

  else if(*pp==nn){
    pp++;
    while((*pp!='\0')&&(*pp>='0'&&*pp<='9'))
      pp++;
    if(*pp=='\0'){
      if(atof(moji)==1.0||atof(moji)==2.0||atof(moji)==3.0){
        goto finish;
      }
      puts("は小数です\n1～3の整数を入力してください\n");
      goto end;
    }
  }

  else if(mi==1 && *pp=='\0'){
    puts("判別できません。\n1～3の整数を入力してください\n");
    goto end;
  }

  else if(*pp==' ' && mi==1){
    while(*pp!='\0' && *pp==' '){
      pp++;
    }
    if(*pp=='\0'){
      puts("はすべて半角空白です。\n1～3の整数を入力してください\n");
      goto end;
    }
  }

  else if(*pp=='\x81' && *(pp+1)=='\x40' && mi==1){
    while(*pp!='\0' && *pp=='\x81' && *(pp+1)=='\x40')
      pp += 2;
    if(*pp=='\0'){
      puts("はすべて全角空白です。\n1～3の整数を入力してください\n");
      goto end;
    }
  }

  else if(*pp=='\xE3' && *(pp+1)=='\x80' && *(pp+2)=='\x80' && mi==1){
    while(*pp!='\0' && *pp=='\xE3' && *(pp+1)=='\x80' && *(pp+2)=='\x80')
      pp += 3;
    if(*pp=='\0'){
      puts("はすべて全角空白です。\n1～3の整数を入力してください\n");
      goto end;
    }
  }
  
  puts("は文字列です\n1～3の整数を入力してください\n");
  end:
    return 1;
  finish:
    return 0;
}