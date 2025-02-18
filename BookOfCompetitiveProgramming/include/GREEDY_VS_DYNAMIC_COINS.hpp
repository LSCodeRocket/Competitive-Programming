#include <iostream>
#include <algorithm>

#define MAX_SIZE 400

int GREEDY_COINS(int* COINS, int COINS_LENGTH, int TARGET) {
    int coins_out = 0;
    int i = COINS_LENGTH - 1;
    int sum = 0;

    while(i >= 0) {
        if(COINS[i] > TARGET - sum) { i--; continue; }

        coins_out++;
        sum += COINS[i];

    }

    return coins_out;
}


int DYNAMIC_COINS(int* COINS, int COINS_LENGTH, int TARGET, int* SOLUTIONS) {

    int minimum = __INT32_MAX__;
    int dynamic_solution = 0;
    for(int i = 0; i < COINS_LENGTH; i++) {
        dynamic_solution = std::min(dynamic_solution, DYNAMIC_COINS(COINS, COINS_LENGTH, TARGET - COINS[i], SOLUTIONS));

    }

    SOLUTIONS[TARGET] = dynamic_solution;
    return dynamic_solution;
}


void DYNAMIC_COINS_RECURSIVE(int* COINS, int COINS_NUM, int TARGET, int* OUTPUT, int* PREVIOUS) {
}