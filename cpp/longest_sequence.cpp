#include <cstdio>

int cmp(int a, int b)
{
    return (a % 2 && !(b % 2)) || (!(a % 2) && b % 2);
}

int longest_seq(int array[], int size, int (*cmp)(int, int))
{
    // We will use a sort of a sliding window from the beginning to the end of
    // the array in orther to find the size of the longest sequence.

    // Check if the array is invalid or empty
    if(!array || size < 1) {
        return 0;
    }

    // Our loop invariant is: [i, j] will contain a subsequence that respects
    // cmp().
    int j = 1;
    int global_l = 1;
    int local_l = 1;

    while (j < size) {
        if (cmp(array[j-1], array[j])) {
            j++;
            local_l++;
        } else {
            if (local_l > global_l) {
                global_l = local_l;
            }
            j++;
            local_l = 1;
        }
    }
    if(local_l > global_l) {
        global_l = local_l;
    }

    return global_l;
}

int main(void) {
    int array[] = {1, 2, 2, 4, 5, 6, 7, 2, 1, 2,3 ,4};
    int size = sizeof(array)/sizeof(int);

    printf("Size (array, seq) = %d, %d\n", size, longest_seq(array, size, &cmp));

    return 0;
}

