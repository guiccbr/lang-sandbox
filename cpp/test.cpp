#include <cstdio>

bool is_power_of_two(int a)
{
    if (a == 0) {
        return false;
    }

    int num_bits = 0;
    for (int i = 0; i < sizeof a; ++i) {
        num_bits += a & 0b1;
        a = a >> 1;
    }
    if (num_bits == 1) {
        return true;
    }

    return false;
}

bool smart_is_power_of_two(int a)
{
    return (a != 0) && (a & (a - 1)) == 0;
}

int main(void) {

    // if (is_power_of_two(4)) {
        // printf("True\n");
    // } else {
        // printf("False\n");
    // }

    int array[] = {1, 2, 3};
    int size = sizeof(array)/sizeof(int) - 1;

    printf("%d\n", size);

    return 0;
}

