#include <stdio.h>
#include <stdbool.h>


enum State {
    Init,
    NewWord,
    MiddleWord,
    EndWord,
    WhiteSpace,
    Terminate
};


int main(int argc, char **argv) {
    char *text = "   abc sabc abcs absc s      s    qs        dsf  lll";
    char current, next;
    int counter = 0;
    bool s_already_counted = false;
    enum State state = Init;
    while (1) {
        current = *text++;
        switch(state){
            case Init:
                if (current == ' '){
                    state = WhiteSpace;
                }
                else if (current == '\0') {
                    state = Terminate;
                }
                else {
                    state = NewWord;
                }
                text--;
                break;
            case NewWord:
                if (current == 's'){
                    counter++;
                    s_already_counted = true;
                }
                next = *text;
                if (next == ' ') {
                    state = WhiteSpace;
                }
                else if (next == '\0') {
                    state = Terminate;
                }
                else {
                    state = MiddleWord;
                }
                break;
            case EndWord:
                next = *text;
                
                if (current == 's' && s_already_counted == false){
                    counter++;
                }
                if (next == ' ') {
                    state = WhiteSpace;
                }
                else if (next == '\0') {
                    state = Terminate;
                }
                break;
            case WhiteSpace:
                next = *text;
                s_already_counted = false;
                if (next == ' ') {
                    state = WhiteSpace;
                }
                else if (next == '\0') {
                    state = Terminate;
                }
                else {
                    state = NewWord;
                }
                break;
            case MiddleWord:
                next = *text;
                if (next == ' ' || next == '\0') {
                    state = EndWord;
                    text--;
                }
                else {
                    state = MiddleWord;
                }
                break;
        }
        if(state == Terminate) {
            break;
        }
    }
    printf("Count %d\n", counter);
}