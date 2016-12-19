#include <iostream>
using namespace std;

int main() {
    int array[] = {1, 1, 2, 2, 3, 22, 5, 9, 22, 11, 8, 45, 2, 23, 21, 4, 36};

	int arraySize = 17;

	// We could sweep the array from right to left shifting the nonzero values to the zero
    // that are found on the right.
    int first_zero = -1;

    for(int i = arraySize - 1; i >= 0 ; i--) {

        // A zero has been found
        if(array[i] == 0) {
            if(first_zero < 0) {
                first_zero = i;
            }
            continue;
        }

        if(first_zero < 0) {
            continue;
        }

        // A nonzero has been found
        array[first_zero] = array[i];
        array[i] = 0;
        first_zero--;

    }

    for (int i = 0; i < arraySize - 1;i++)
      cout << array[i] << ", ";
    cout << array[arraySize - 1];
    return 0;
}

