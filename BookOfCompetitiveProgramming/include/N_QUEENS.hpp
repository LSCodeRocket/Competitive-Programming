#define MAX_SIZE 400

#include <iostream>
#include <vector>

int SEARCH(int y, int N, int* count, int* DIAGONAL_1, int* DIAGONAL_2, int* COLUMNS ) {
    if(y == N) {(*count) += 1; return *count; }
    for(int x = 0; x < N; x++) {

        bool is_QUEEN_TARGETTING = DIAGONAL_1[x + y] == 1 || 
            DIAGONAL_2[x - y + N - 1] == 1 || 
            COLUMNS[x] == 1; 
        if(is_QUEEN_TARGETTING) { continue; }

        DIAGONAL_1[x + y] = 1;
        DIAGONAL_2[x - y + N - 1] = 1;
        COLUMNS[x] = 1;
        
        SEARCH(y+1, N, count, DIAGONAL_1, DIAGONAL_2, COLUMNS);

        DIAGONAL_1[x + y] = 0;
        DIAGONAL_2[x - y + N - 1] = 0;
        COLUMNS[x] = 0;
        
    }

    return *count;
}

int N_QUEENS(int N) {
    int count = 0;
    int DIAGONAL_1[MAX_SIZE];
    int DIAGONAL_2[MAX_SIZE];
    int COLUMNS[MAX_SIZE];
    
    if(2*N - 1> MAX_SIZE) { std::cout << "N IS TOO HIGH" << std::endl; return -1; }

    return SEARCH(0, N, &count, DIAGONAL_1, DIAGONAL_2, COLUMNS);

}