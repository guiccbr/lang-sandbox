#include <stdio.h>

int (*f(char a))() {
    printf("Func f %c\n", a);
    return 0;
}

int main(void) {
    int (*(*p_to_f)(char))() = &f;

    p_to_f('y');

    return 0;
}

