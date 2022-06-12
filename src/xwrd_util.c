#include <stdio.h>
#include <stdlib.h>
#include "xwrd_util.h"
#include "hiragana.h"
#include "xwrd.h"

void check_fp(FILE* fp){

    if(fp == NULL){
        printf("入力ファイルが読み込みできません。");
        exit(1);
    }
}

/*************************************************
 * xwrd_read
 * @param file_name ファイル名
 * @param hint      ヒント構造体の配列
 * ***********************************************/
int xwrd_read(const char* file_name, hint* h){
    FILE* fp;
    int i;
    fp = fopen(file_name, "r");

    check_fp(fp);
    for(i = 0; i < HINT_MAX_NUM; i++){
        int received_num = fscanf(fp, "%d %s %d %d %d %s",\
              &h[i].index,\
              h[i].muki_str,\
              &h[i].pos_x,\
              &h[i].pos_y,\
              &h[i].anslen,\
              h[i].desc\
         );
        
        // check arguments
        if(received_num != 0 && received_num != 6 ){
            //printf("ファイルの内容が不正です\n");
            //printf("一行に入る変数の数: %d\n", received_num);
            break;
        }
        if(received_num == 0)continue;

        // position check 
        if(h[i].pos_x < 1 || h[i].pos_x > 6){
            printf("x座標の位置が不正です。: %d", h[i].pos_x);
            exit(1);
        }
        if(h[i].pos_y < 1 || h[i].pos_y > 6){
            printf("y座標の位置が不正です。: %d", h[i].pos_y);
            exit(1);
        }

        if(h[i].anslen < 1 || h[i].anslen > 6){
            printf("文字列長さが不正です。: %d", h[i].pos_y);
            exit(1);
        }
        // check vec
        if(is_same_hiragana(h[i].muki_str, "たて")){
            h[i].muki = VT;
        } else if(is_same_hiragana(h[i].muki_str, "よこ")){
            h[i].muki = HZ;
        } else {
            printf("向きは'たて'か'よこ'のみです。\n");
            exit(1);
        }
            
        printf("%d %s\n",h[i].index, h[i].desc);
        
    }
    //while(fgets(target[cnt++], FILE_BYTES_LEN, fp) != NULL);

    fclose(fp);
    return i;
}

//int str_to_num(char s_num){
//    int res = atoi(s_num);
//    if(res == 0){
//        printf("Invalid argument %c in str_to_num\n", s_num);
//    }
//    return s_num;
//
//}
//void xwrd_read(const char* file_name, char target[HINT_MAX_NUM][FILE_BYTES_LEN]){
//    FILE* fp;
//    int cnt = 0;
//    char ans_array[HINT_MAX_NUM][FILE_BYTES_LEN] = {'\0'};
//    fp = fopen(file_name, "r");
//
//    check_fp(fp);
//    
//    fscanf_s(fp, "%d")
//    //while(fgets(target[cnt++], FILE_BYTES_LEN, fp) != NULL);
//
//    printf("%s\n", target[cnt]);
//    fclose(fp);
//
//}
void xwrd_read_ans(const char* file_name, char target[][37]){
    FILE* fp;
    int cnt = 0;
    fp = fopen(file_name, "r");
    check_fp(fp);
    while(fgets(target[cnt++], FILE_BYTES_LEN, fp) != NULL)
    ;
    fclose(fp);
}

//
void input_hint_number(int* num, int hint_len){
    char buf[3] = {'\0'};
    while(1){

        scanf("%2s", buf);
        *num = atoi(buf);
        if(*num < 1 || hint_len < *num){
            printf("Error: please input number 1 to %d -> ", hint_len);
            continue;
        }
        break;
    }
}


