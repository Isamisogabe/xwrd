#include <stdio.h>
#include "hiragana.h"

void test_hiragana(){
    printf("\nTest test_hiragana\n");
    const char* hiraganas = "ひらがs";
    printf("Input: %s\n", hiraganas);
    int res = check_hiragana(hiraganas, 4);

    if(res == 0){
        printf("OK");
    } else {
        printf("ERROR");
    }

}

void test_hiragana_to_num(){
    printf("\nTest test_hiragana_to_num\n");
    char* hiragana = "ひ";
    printf("Input: %s\n", hiragana);
    int res = hiragana_to_num(hiragana);
    printf("\nres : %x\n", res);
    if(res == 0xe381b2){
        printf("OK");
    } else {
        printf("ERROR");
    }

}
int main(){
    test_hiragana();
    test_hiragana_to_num();
}