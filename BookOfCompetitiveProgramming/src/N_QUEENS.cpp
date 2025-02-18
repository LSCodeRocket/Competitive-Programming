#include <iostream>
#include "../include/N_QUEENS_PERMUTATION.hpp"

int main() {

    for(int i = 1; i <= 21; i++) {
        std::cout << "q(" << i << ") == " << N_QUEENS(i) << "\n";
    }

    return 0;

}