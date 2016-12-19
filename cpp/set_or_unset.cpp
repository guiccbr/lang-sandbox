#include <cmath>
#include <cstdio>
#include <vector>

// Return the minimum modulus by multiplying each element for -1 or +1.
int min_mod(std::vector<int> &items, int size, int *num_op,
            std::vector<int> &storage)
{
    // Base case. There's no element to add. Mod is zero.
    if (size == 0) {
        return 0;
    }

    // Check if we have already calculated this value
    int result = storage[size - 1];
    if(result != -1) {
        return result;
    }

    // Update number of iterations
    (*num_op)++;

    // Let's check the last element. We need to check if multiplying it by
    // minus one or plus one increases the module or diminishes it.
    int min_mod_neg = min_mod(items, size - 1, num_op, storage) - items[size - 1];
    int min_mod_pos = min_mod(items, size - 1, num_op, storage) + items[size - 1];

    result = std::abs(min_mod_neg) < std::abs(min_mod_pos) ? min_mod_neg
                                                           : min_mod_pos;

    //storage[size - 1] = result;
    return result;
}

int min_mod_dynamic(std::vector<int> &items, int size, int *num_op)
{
    std::vector<int> storage(size, -1);

    return std::abs(min_mod(items, size, num_op, storage));
}

int main(void)
{
    // List of items
    std::vector<int> items = {1, 2, 3};

    // Maximum weight
    int max_mod_element = 100;

    // Store number of operations
    int num_op = 0;

    printf("Minimum mod %d\n", min_mod_dynamic(items, items.size(), &num_op));
    printf("Number of operations: %d\n", num_op);

    return 0;
}

