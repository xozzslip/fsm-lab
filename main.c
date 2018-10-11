#include <stdio.h>


enum State {
    Init,
    NewWord,
    MiddleWord,
    EndWord,
    WhiteSpace,
    Terminate
};


int main(int argc, char **argv) {
    char *text = "abc sabc abcs absc s      sss";
    char current, next;
    int counter = 0;
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
                if (current == 's'){
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