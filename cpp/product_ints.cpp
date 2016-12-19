#include <cstdio>

int max_prod_three(std::vector<int> input) {

    // Find the highest product of three numbers from the input. We need to
    // make sure that this approach will work with negative values as well.

    // For example:
    // input: v = [2, 3, 4, 1, 12, 1]
    // output: r = 154 = 3*4*12
    //
    // input: v = [2, -3, -4, 1, -12, 1]
    // output: r = 96 = 2 * -4 * -12

    // To solve this problem in O(n) with a greedy strategy we need to consider
    // the following:

    // What are the values that we need to store at each iteration to make sure
    // that the currently evaluated value will affect possitively the result?
    // In our case, what do we need to save in order to know if replacing one
    // of ther previous 3 values chosen with the new one will result in a
    // higher product?

    // First of all, it seems reasonable to store the last *max_prod_three* value.
    // Then, for the next value, we decide if that one affects positively the
    // result by replacing it with one of the three previous values. But which
    // one? It seems reasonable to store the *lowest*. Will that work?

    // Well, that seems true if we limit our problem only for positive numbers.
    // But that's not the case. A negative lowest number could possibly result
    // in a higher value than the previous one if multiplied by another
    // negative number. Negative numbers are making the problem a little more
    // complicated.

    // To solve that problem, let's consider the subproblem of highest product
    // of two an see if we can get somewhere closer to the answer:

    // To follow that value using a greedy approach we just need to iterate the
    // array element by element, replacing the one of the two previous with the
    // current. That doesn't work with negative values either since we might
    // replace that value. What about if we decide to store both then? The
    // highest and the lowest possibly negative product of two?

    // Then we would have something like:
    // Input: v = [-10, 1, 5, -1]
    //
    // It 1: r = -10 * 1 = -10
    // It 2: r = 5 * 1 = 5
    // It 3: r = 5 * 1 = 5 (wrong)

    // Let's do the following instead: 
    //
    // It 1: r = -10 * 1, max = 1, min = -10
    // It 2: r = 5 = max(r, max * 5, min * 5), max = 5, min = -10
    // It 3: r = max(r, max * -1, min * -1) = 10, max = 5, min = -10
    //
    // This way, we can assure that the highest product of two will be found.

    // Having found the highest product of two, how do we get the highest
    // product of three then?
    // Let's store the two highest and the two lowest
    //
    // This way:
    //
    // It 1: r = -10 * 1 * 5, max1, max2 = 5, 1, min1, min2 = -10, 1 
    // It 2: r = 5 = max(r, max1 * max2 * 5, min1 * min2 * 5), max = 5, min = -10
    // It 3: r = max(r, max * -1, min * -1) = 10, max = 5, min = -10

    int max_prod_two = 1; 
    int min_prod_two = 1;
    int max_prod_three = 1;

    for (int i = 0; i < input.size(); i++) {

        // Check if the current value generates a new highest product of three
        int candidate_max_prod_three = max_prod_two * input[i];
        if(candidate_max_prod_three > max_prod_three) {
            max_prod_three = max_prod_two * i;
        }

        candidate_max_prod_three = min_prod_two * input[i];
        if(candidate_max_prod_three > max_prod_three) {
            max_prod_three = min_prod_two * i;
        }

        // Check if the current value generates a new highest product of two
        if (
    }

    
}

int main(void) {

    std::vector<int> test_array = {1, 2, 3, 4, 5, 6};

    int res = max_pod_three(test_array);

    std::cout << "Max product of three: " << res << std::endl;
}

