#include <iostream>
#include "../include/N_GRID_PATHS.hpp"

int main() {
    int GRID_NUM = 0;
    for(int i = 3; i <= 10; i++) {
        
        GRID_NUM = N_GRID_PATHS(i);
        std::cout << "G(" << i << ") = " << GRID_NUM << std::endl;
    }
    return 0;
}