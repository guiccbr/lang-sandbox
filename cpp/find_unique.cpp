#include <cstdio>

// in = input
// out = result
// size = size of the array
// return = -1 in case the value has not been found
//           0 in case of success
int find_positive_unique(int *in, int *out, int size)
{
    // Since it is guaranteed that the values in the array are within the range
    // [1 - 100], we will use a simple array as a hash, storing the number of
    // times a given id has appeared.
    int ids[101] = {0};

    // Fill up the hash
    for (int i = 0; i < size; ++i) {
        ids[in[i]]++;
    }

    // Find the unique element
    for (int i = 0; i < 101; ++i) {
        if (ids[i] == 1) {
            *out = i;
            return 0;
        }
    }

    // No unique element has been found. Return error.
    return -1;
}

int main(void)
{

    int array[] = {1, 2, 3, 3, 5, 1, 5, 4, 2};
    int size = sizeof(array) / sizeof(int);

    int result;
    int err = find_positive_unique(array, &result, size);

    if (err == -1) {
        printf("Unique has not been found\n");
    } else {
        printf("Unique has been found: %d\n", result);
    }

    return 0;
}

