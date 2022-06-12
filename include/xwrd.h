#ifndef _XWRD_H_
#define _XWRD_H_
#define PNL 6
// description 
#define DESC_LEN (150 * 6 + 1)

typedef enum panel_is {
    EMPTY,
    OCCUPYED,
    BLACK
} panel_is;

typedef enum vec {
    HZ,
    VT
} vec;

typedef struct panel {
    panel_is p;
    // 6 byte
    char moji[7];
} panel ;

typedef struct hint {
    int index;
    char desc[DESC_LEN];
    // max 6 moji
    char answer[37];
    int anslen;
    char muki_str[7];
    vec muki;
    int pos_x;
    int pos_y;
} hint;

typedef struct board {
    panel p[PNL][PNL];
} board;

void show_tab(board* b);
void compare_tab(board* b, board* h);

void init_tab(board* b, char dat[][37]);

int check_tab(board* b, board* ans);

void allocate_hiragana_to_board(board* b, char* t_str, int x, int y,int len, vec v);

#endif
