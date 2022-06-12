#ifndef _HIRAGANA_H_
#define _HIRAGANA_H_
#define HIRA_BYTE_SIZE 3
#define HIRA_OCT_SIZE 6
int check_hiragana(char* hira, int len);

int hiragana_to_num(char hira[3]);

int is_same_hiragana(char* h1, char* h2);
void input_hiragana(char* target, int len);
#endif