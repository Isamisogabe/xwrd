#include <stdio.h>
#include "xwrd.h"
#include "xwrd_util.h"
#include "hiragana.h"

void test_allocate_hiraga_to_board() {
    board my_board = {0};
    hint hints[15]= {0};
    int num = 1;
    hint* h = &hints[num - 1];
    char hira[] = "としみち";
    char dat[6][37] = {'\0'};
    // read hint
    xwrd_read("dat/hint.dat", hints);

    xwrd_read_ans("dat/init.dat", dat);
    init_tab(&my_board, dat);
    //printf("%d", h->anslen);
    //printf("%d", hints[0].anslen);
    allocate_hiragana_to_board(&my_board,\
        hira,\
        h->pos_x,\
        h->pos_y,\
        h->anslen,\
        h->muki\
    );
    // check

    show_tab(&my_board);
}
int main() {
    test_allocate_hiraga_to_board();
}