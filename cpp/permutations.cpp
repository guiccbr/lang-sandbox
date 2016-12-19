#include <cstdio>
#include <cstring>

void print_permutations_rec(char a[], int size, int except) {

    for(int i=0; i<size; i++) {
        if (a[i] == 0) {
            continue;
        }

        printf("%c", a[i]);
        char a_swp = a[i];
        a[i] = 0;
        print_permutations_rec(a, size, i);
        a[i] = a_swp;
    }
}

void print_permutations(char a[]) {

    int size = strlen(a);

    print_permutations_rec(a, size, -1);
}

int main(void) {

    char a[] = "ab";

    print_permutations(a);

    return 0;
}
