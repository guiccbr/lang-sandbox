#include <stdio.h>

void getProductsOfAllIntsExceptAtIndex(const int* input, int* output, int size) {
    
    int acc = 1;
    for(int i = 0; i < size; i++) {
        output[i] = acc;
        acc *= input[i];
    }
    
    acc = 1;
    for(int i = size-1; i >= 0; i--) {
        output[i] *= acc;
        acc *= input[i];
    }
}

int get_max_profit_n_sq(int* stock_prices, int size) {
 
    int profit = 0;
    for (int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            if(stock_prices[j] - stock_prices[i] > profit) {
                profit = stock_prices[j] - stock_prices[i];
            }
        }
    }
    
    return profit;    
}

int get_max_profit_n(int* stock_prices, int size) {
 
    if(size < 2) {
        printf("Error: Stock prices should have at least two elements");
        return 0;
    }
    
    int profit = stock_prices[1] - stock_prices[0];
    int lowest = stock_prices[0];
    
    for (int i = 1; i < size; i++) {
        int candidate_profit = stock_prices[i] - lowest;
        if(candidate_profit > profit) {
            profit = candidate_profit;
        }
        if(stock_prices[i] < lowest) {
            lowest = stock_prices[i];
        }
    }
    
    return profit;    
}

int main(void) {

    // Maximum Profit
	int stock_prices_yesterday[6] = {10, 4, 3, 2, 1, 0};
    
    int max_profit_n = get_max_profit_n(stock_prices_yesterday, 6);
    int max_profit_n_sq = get_max_profit_n_sq(stock_prices_yesterday, 6);

    printf("Max Profit: %d %d\n", max_profit_n, max_profit_n_sq);

	// All Products Except Index 
    int input[4] = {1, 3, 4, 21};
    int output[4];
    
    getProductsOfAllIntsExceptAtIndex(input, output, 4);
    printf("Products: %d %d %d %d\n", output[0], output[1], output[2], output[3]);
}

