#include <stdio.h>
#include "count.h"


int main() {
    char *words[] = {
        "sss ", 
        "ss ss ", 
        "ss s ", 
        "ss  ",
        "ssqs ",
        "ssl ",
        "s ss ",
        "s s ",
        "s  ",
        "sms ",
        "sn ",
        " ss ",
        " s ",
        "  ",
        "qsss ",
        "lss ",
        "ns ",
        "q ss ",
        "q s ",
        "q  ",
        "qqss ",
        "qqs ",
        "qq "
    };
    int answers[] = {1, 2, 1, 1, 
                     1, 0, 1, 0, 
                     0, 1, 0, 1,
                     0, 0, 0, 0,
                     0, 1, 0, 0,
                     0, 0, 0};
    int words_c = sizeof(words) / sizeof(*words);
    int i, ans, cnt;
    char *word;
    int failed = 0;
    for(i = 0; i < words_c; i++) {
        word = words[i];
        cnt = count(word);
        ans = answers[i];
        if(cnt != ans){
            printf("%i\n", i);
            failed++;
        }
    }
    if(failed == 0) {
        printf("OK\n");
        return 0;
    }
    return -1;
}