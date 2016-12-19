#include <cmath>
#include <cstdio>
#include <vector>

// Longest common subsequence
// Return the size of the longest common subsequence
int lcs(std::vector<int> &a, int a_size, std::vector<int> &b, int b_size,
        int *num_op, std::vector<std::vector<int>> &storage)
{
    // If any of the arrays is empty, the longest subsequence between them has
    // zero length.
    if (a_size == 0 || b_size == 0) {
        return 0;
    }

    // Check if the value already exists in the storage
    int result = storage[a_size - 1][b_size - 1];
    if (result != -1) {
        return result;
    }

    // Increment num_op
    (*num_op)++;

    // If the last element of both arrays are equal, it means that we should
    // add it to the solution and sum with the LCS of the initial elements.
    if (a[a_size - 1] == b[b_size - 1]) {
        result = 1 + lcs(a, a_size - 1, b, b_size - 1, num_op, storage);
    } else {

        // If they are different, we must select the longest subsequence among
        // both arrays skipping the last element.
        result = std::max(lcs(a, a_size, b, b_size - 1, num_op, storage),
                          lcs(a, a_size - 1, b, b_size, num_op, storage));
    }

    storage[a_size - 1][b_size - 1] = result;
    return result;
}

int lcs_dynamic(std::vector<int> &a, int a_size, std::vector<int> &b,
                int b_size, int *num_op)
{
    std::vector<std::vector<int>> storage(a_size, std::vector<int>(b_size, -1));

    int result = lcs(a, a_size, b, b_size, num_op, storage);

    return result;
}

int main(void)
{
    std::vector<int> a = {3, 4, 5};
    int a_size = a.size();

    std::vector<int> b = {2, 5, 2, 3, 6, 8, 1, 4, 5};
    int b_size = b.size();

    // Store number of operations
    int num_op = 0;

    printf("Longest subsequence length: %d\n",
           lcs_dynamic(a, a_size, b, b_size, &num_op));
    printf("Number of operations: %d\n", num_op);

    return 0;
}

