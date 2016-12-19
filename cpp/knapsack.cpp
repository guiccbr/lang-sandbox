#include <cmath>
#include <cstdio>
#include <vector>

struct item {
    item(float v, float w)
    {
        value = v;
        weight = w;
    }

    float value;
    float weight;
};

// Return the maximum weight of the knapsack to optimize value
float knapsack(std::vector<item> &items, int size, int max_weight,
               int *num_op, std::vector<std::vector<int>> &storage)
{
    // Base case. We have no element to add, or the sack is already full. We
    // return no value. No profit at all since there's nothing in the sack.
    if(size == 0 || max_weight == 0) {
        return 0;
    }

    // Let's check if this value already exists
    int result = storage[size-1][max_weight-1];

    if(result != -1) {
        return result;
    }

    // Update number of iterations
    (*num_op)++;

    // Lets analyze the last item. If it does not fit in the remaining weight,
    // let's just simply ignore it. In the first iteration, it's clear that
    // this value will not be in the solution, because we will have the real
    // max_weight and the value is heavier than that. In subsequent calls, it's
    // not that clear, but lets see.
    if (items[size - 1].weight > max_weight) {
        // Item does not fit in the available space. The solution does not
        // contain it.
        result = knapsack(items, size - 1, max_weight, num_op, storage);
    } else {
        // If the element fits in the ramaining weight, then we need to check if
        // it's better to include it or not inside the sack.
        result = std::max(
            items[size - 1].value +
                knapsack(items, size - 1, max_weight - items[size - 1].weight,
                         num_op, storage),
            knapsack(items, size - 1, max_weight, num_op, storage));
    }

    //storage[size - 1][max_weight - 1] = result;
    return result;
}

// Store the values to avoid recalculations
int knapsack_dynamic(std::vector<item> &items, int size, int max_weight,
                       int *num_op)
{
    // Create a storage to store values that have already been calculated
    std::vector<std::vector<int>> storage(size,
                                          std::vector<int>(max_weight, -1));

    return knapsack(items, size, max_weight, num_op, storage);
}

int main(void)
{
    // List of items
    std::vector<item> items = {item(1, 2), item(2, 2), item(4, 2), item(1, 9),
                               item(1, 2), item(2, 2), item(4, 2), item(1, 9)};

    // Maximum weight
    int w = 10;

    // Store number of operations
    int num_op = 0;

    printf("Maximum value for a maximum weight of %d: %d\n", w,
           knapsack_dynamic(items, items.size(), w, &num_op));
    printf("Number of operations: %d\n", num_op);

    return 0;
}

