#include <cstdio>

bool openers_are_closed(char * start, char *end, char opn) {

    char * curr_char = str;

    while(*curr_char != '\0') {

        if( *curr_char == opn - 1 ) {
            end = curr_char + 1;
            return true;
        }

        if( *curr_char == '{' || * curr_char == '[' || * curr_char == '(') {
            if(!openers_are_closed(curr_char + 1, *curr_char) {
                end = curr_char + 1;
                return false;
            }else {
                end - curr_char + 1;
                return true;
            }
        }
    }
}

int main(void) {
    const char * str = "{asdqwe{asdqwe{dsdqwe}[ads(qw)]}}";

    if(openers_are_closed(str)) {
        printf("True\n");
    }else {
        printf("False\n");
    }

    return 0;
}
