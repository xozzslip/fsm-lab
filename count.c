#include <stdio.h>


enum State {
    INIT,
    S_,
    S_S, 
    W
};


int count(char *text) {
    char current;
    int counter = 0;
    enum State state = INIT;
    while (1) {
        current = *text++;
        switch(state){
            case INIT:
                if(current == 's') {
                    state = S_;
                }
                else if(current == ' ' || current == '\0') {
                    state = INIT;
                }
                else {
                    state = W;
                }
                break;
            case S_:
                if(current == 's') {
                    state = S_S;
                }
                else if(current == ' ' || current == '\0') {
                    state = INIT;
                }
                else {
                    state = S_;
                }
                break;
            case S_S:
                if(current == 's') {
                    state = S_S;
                }
                else if(current == ' ' || current == '\0') {
                    state = INIT;
                    counter++;
                }
                else {
                    state = S_;
                }
                break;
            case W:
                if(current == 's') {
                    state = W;
                }
                else if(current == ' ' || current == '\0') {
                    state = INIT;
                }
                else {
                    state = W;
                }
                break;
        }
        if (current == '\0') {
            break;
        }
    }
    return counter;
}
