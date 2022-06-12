#include "xwrd.h"
#ifndef _XWRD_UTIL_H_
#define _WWRD_UTIL_H_


#define UTF_LEN 6
#define HIRA_LEN 3
#define FILE_BYTES_LEN (15 + UTF_LEN * 150) + 1
#define HINT_MAX_NUM 15

typedef enum menu {
    CONTINUE,
    SUBMIT,
    END
} menu;

int xwrd_read(const char* file_name, hint* hint);

void xwrd_read_ans(const char* file_name, char target[][37]);

void input_hint_number(int* num, int hint_len);
#endif