#include <iostream>
#include "../include/N_GRID_PATHS_UNOPTIMIZED.hpp"

int main() {
    int GRID_NUM = 0;
    for(int i = 3; i <= 7; i++) {
        
        GRID_NUM = N_GRID_PATHS(i);
        std::cout << "G(" << i << ") = " << GRID_NUM << std::endl;
    }
    return 0;
}