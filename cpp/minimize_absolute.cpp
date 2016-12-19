#include <cstdio>

// in = input
// out = result
// size = size of the array
void minimize_absolute_sum(int *in, int *out, int size)
{



}

int main(void)
{
    int array[] = {4, 4};
    int size = sizeof(array) / sizeof(int);

    int result;
    minimize_absolute_sum(array, &result, size);

    printf("Minimized sum:\n", result);

    return 0;
}

