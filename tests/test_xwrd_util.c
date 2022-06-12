#include <stdio.h>
#include "xwrd_util.h"
#include "xwrd.h"
#include "hiragana.h"

void test_xwrd_read(){

    char* file_name = "dat/hint.dat";
    hint h[15] = {0};
    printf("check file ");

    xwrd_read(file_name, h);

    // check 

    for(int i = 0; i < 15 ; i++) {
        printf("h[%d]\n", i);
        printf("index: %d\n", h[i].index);
        printf("pos_x: %d\n", h[i].pos_x);
        printf("pos_y: %d\n", h[i].pos_y);
        printf("anslen: %d\n", h[i].anslen);
        printf("muki: %d\n", h[i].muki);
    }
}

void test_xwrd_read_ans(){
    const char file_name[] = "dat/seikai.dat";
    char dat[6][37] = {'\0'};

    xwrd_read_ans(file_name, dat);
    for(int i = 0; i < 6; i++){
        printf("str: %s", dat[i]);
    }
    printf("\n");
}
void test_init_tab(){
    const char file_name[] = "dat/seikai.dat";
    char dat[6][37] = {'\0'};

    xwrd_read_ans(file_name, dat);

    board my_board = {0};
    init_tab(&my_board, dat);
    show_tab(&my_board);

}

void test_check_tab(){
    const char file_name[] = "dat/seikai.dat";
    char dat[6][37] = {'\0'};

    xwrd_read_ans(file_name, dat);

    board my_board = {0};
    init_tab(&my_board, dat);
    show_tab(&my_board);

    int res = check_tab(&my_board, &my_board);

    if(res == 36){
        printf("test_check_tab:ok");
    } else {

        printf("Error: the num of correct tab is %d", res);
    }

}

void test_is_same_hiragana(){
    char hira1[] = {"たて"};
    char hira2[] = {"よこ"};
    char hira3[] = {"よこ＊"};
    printf("\nTest: is_same_hiragana\n");
    printf("INPUT: %s %s\n", hira1, hira1);
    int res = is_same_hiragana(hira1, hira1);
    printf("Expected: 1, Result: %d\n", res);
    printf("INPUT: %s %s\n", hira1, hira2);
    res = is_same_hiragana(hira1, hira2);
    printf("Expected: 0, Result: %d\n", res);
    printf("INPUT: %s %s\n", hira2, hira3);
    res = is_same_hiragana(hira2, hira3);
    printf("Expected: 0, Result: %d\n", res);
}
void test_input_number() {
    int num;
    input_number(&num);

}
//void test_xwrd_read(){
//
//    char* file_name = "dat/hint.dat";
//    char ans_array[HINT_MAX_NUM][FILE_BYTES_LEN] = {'\0'};
//    printf("check file ");
//    xwrd_read(file_name, ans_array);
//
//    // check 
//    for(int i = 0; i < 15 ; i++) {
//        printf("read str: %s\n", ans_array[i]);
//    }
//}
//
int main() {
    test_xwrd_read();
    test_is_same_hiragana();
    test_xwrd_read_ans();
    test_init_tab();
    test_check_tab();
}