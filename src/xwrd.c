#include "xwrd.h"
#include "xwrd_util.h"
#include "hiragana.h"
#include <stdio.h>
#include <string.h>

#define XWRD_BUF 100
/**************************
 * show_tab
 * 票の表示
 * ***********************/
void show_tab(board* b){
    printf("ーーーーーー\n");
    printf("\n");
    for(int i = 0; i < PNL ; i++) {
        for(int j = 0; j < PNL ; j++) {
            printf("%s", b->p[i][j].moji);
        }
        printf("\n");
    }
    printf("\n");
    printf("ーーーーーー\n");
}
/**************************
 * compare_tab
 * 表の比較
 * ***********************/
void compare_tab(board* b, board* h){
    printf("ーーーーーーーーーーーーーー\n");
    printf("現在の解答　　　ヒントの位置\n");
    for(int i = 0; i < PNL ; i++) {
        for(int j = 0; j < PNL ; j++) {
            printf("%s", b->p[i][j].moji);
        }
        printf("　　");
        for(int j = 0; j < PNL ; j++) {
            printf("%s", h->p[i][j].moji);
        }
        printf("\n");
    }
    printf("\n");
    printf("ーーーーーーーーーーーーーー\n");
}
/**************************
 * compare_tab
 * 表の初期化
 * ***********************/
void init_tab(board* b, char dat[][37]){

    for(int i = 0; i < PNL ; i++) {
        char* line = *(dat + i);
        for(int j = 0; j < PNL ; j++) {
            strncpy(b->p[i][j].moji, line+(HIRA_LEN*j), HIRA_LEN);
        }
    }
}


/**************************
 * check_tab
 * 表の評価
 * ***********************/
int check_tab(board* b, board* ans){
    int count = 0;
    for(int i = 0; i < PNL ; i++) {
        for(int j = 0; j < PNL ; j++) {
            if(is_same_hiragana(b->p[i][j].moji, ans->p[i][j].moji)){
                count++;
            }
        }
    }
    return count;
}
/**************************
 * allocate_hiragana_to_board
 * 表にひらがなを割り当て
 * ***********************/
void allocate_hiragana_to_board(board* b, char* t_str, int x, int y,int len, vec v){
    if (v == VT){
        for(int i = 0; i < len; i++){
            //printf("before: %s", b->p[y-1+i][x-1].moji);
            strncpy(b->p[y-1+i][x-1].moji, t_str+(HIRA_LEN*i), HIRA_LEN);
            //printf("after: %s", b->p[y-1+i][x-1].moji);
        }

    } else {
        for(int i = 0; i < len; i++){
            //printf("before: %s", b->p[y-1][x-1+i].moji );
            strncpy(b->p[y-1][x-1+i].moji, t_str+(HIRA_LEN*i), HIRA_LEN);
            //printf("after: %s", b->p[y-1][x-1+i].moji);
        }
    }

}


