
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hiragana.h"

/*************************************************
 * hiragana_to_num
 * @param hira --- change hiragana to encoded value
 * 
 * ひらがなを16進数のエンコードされた数値に変更する
 * 
 * *********************************************** */
int hiragana_to_num(char hira[3]){

    int sum = 0;
    for(int i = 0; i < HIRA_BYTE_SIZE; i++){
        int num = 0x000000ff & (int)hira[i];

        //printf("hex %x\n",num);
        //printf("deg %d\n",num);
        sum += num;
        sum <<= 8;
    }
    sum = (sum >> 8 )  & 0x00ffffff;
    return sum;
}
/*************************************************
 * check_hiragana 
 * @param hira --- change hiragana to encoded value
 * 
 * ひらがなの文字列を引数とし、
 * すべてひらがなである場合は0,
 * 一部ひらがなでない場合は1
 * を返す。 
 * ***********************************************/
int check_hiragana(char* hira, int len){
    const int start = 0x00e38181;
    const int end   = 0x00e3829e;
    int flag = 0;

    for(int i = 0; i < len; i++){
        char buf[HIRA_BYTE_SIZE] = {'\0'};
        int num_hira;
        strncpy(buf, &hira[HIRA_BYTE_SIZE * i], HIRA_BYTE_SIZE);

        //printf("moji buf: %s\n", buf);
        num_hira = hiragana_to_num(buf);
        //printf("moji hex: %x\n", num_hira);
        if(num_hira < start || num_hira > end){
            flag = 1;
        }
    }

    return flag;
}

int is_same_hiragana(char* h1, char* h2){
    int flag = 1;
    while(*h1 != '\0' || *h2 != '\0'){
        if(*h1 != *h2){
            flag = 0;
            break;
        }
        h1++;h2++;
    }
    return flag;
}
void input_hiragana(char* target, int len){
    while(1){
        scanf("%36s", target);
        //printf("%s", target);
        if(target[0] == '0'){
            exit(1);
        }
        if(strlen(target) != (len * HIRA_BYTE_SIZE)){
            printf("長さが一致しません。再入力してください。\n");
            printf("強制終了する場合0を入力\n");
            continue;
        }
        if(check_hiragana(target, len)){
            printf("ひらがなを入力してください。\n");
            printf("強制終了する場合0を入力\n");
        } else {
            break;
        }
    }
}