#include <stdio.h>
#include <stdlib.h>
#include "xwrd.h"
#include "xwrd_util.h"
#include "hiragana.h"

int main(void) {

    board my_board = {0};
    board refer_board = {0};
    board ans_board = {0};
    hint hints[HINT_MAX_NUM]= {0};
    int  hint_len;
    char dat[PNL][UTF_LEN * PNL + 1] = {'\0'};
    char ans_dat[PNL][UTF_LEN * PNL + 1] = {'\0'};

    xwrd_read_ans("dat/init.dat", dat);
    xwrd_read_ans("dat/seikai.dat", ans_dat);
    init_tab(&my_board, dat);
    init_tab(&refer_board, dat);
    init_tab(&ans_board, ans_dat);

    // read hint
    hint_len = xwrd_read("dat/hint.dat", hints);

    show_tab(&my_board);
    menu menu;
    while(menu != END){
        int num;
        char sel;
        hint h;
        char input_str[37];
        printf("ヒント番号を入力 - > ");
        input_hint_number(&num, 9);
        h = hints[num - 1];
        printf("%d: %s\n", h.index, h.desc);
        printf("ひらがなを入力（小文字は大文字に) - >");
        input_hiragana(input_str, h.anslen);
        allocate_hiragana_to_board(&my_board,\
            input_str,\
            h.pos_x,\
            h.pos_y,\
            h.anslen,\
            h.muki\
        );
        compare_tab(&my_board, &refer_board);
        // ignore line feed 
        getchar();
        printf("まだ続けますか？\n つづける(1又はエンターキーを入力) 提出して採点(2) 終了(3) - > ");
        sel = getchar();
        
        if(sel == '1' || sel == '\n'){
            menu = CONTINUE;
        } else if( sel == '2' ){
            int points;
            menu = SUBMIT;
            points = 100 * ((double)check_tab(&my_board, &ans_board) / (PNL * PNL)) ;
            printf("あなたの得点は100点中%d点です。\n", points);
            if(points >= 100){
                printf("Great! \n");
            } else if(points >= 50){
                printf("Great! \n");
            } else {
                printf("Not so good.\n");
            }
            
            printf("あなたの答案と解答はこちらになります\n");
            compare_tab(&my_board, &ans_board);
            exit(2);
        } else if (sel == '3'){
            menu = END;
        } else {
            menu = CONTINUE;
        }
    }
}