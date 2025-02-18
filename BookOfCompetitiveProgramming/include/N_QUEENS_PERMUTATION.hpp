#define MAX_SIZE 400

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

int N_QUEENS(int N) {
    int count = 0;
    int DIAGONAL_1[MAX_SIZE];
    int DIAGONAL_2[MAX_SIZE];
    
    if(2*N - 1> MAX_SIZE) { std::cout << "N IS TOO HIGH" << std::endl; return -1; }

    std::vector<int> QUEEN_X_POS(N);
    for(int i = 0; i < N; i++) {
        QUEEN_X_POS[i] = i;
    }

    do {
        bool isVALID = true;

        for(int i = 0; i < N; i++) {
            
            int x = QUEEN_X_POS[i];
            int y = i;
            bool isQUEEN_TARGETTING = DIAGONAL_1[x + y] == 1 || DIAGONAL_2[x - y + N - 1] == 1;

            if(isQUEEN_TARGETTING) {
                isVALID = false;
                break;
            }

            DIAGONAL_1[x + y] = 1;
            DIAGONAL_2[x - y + N - 1] = 1;

        }

        if(isVALID) {
            count++;
        }

        memset(DIAGONAL_1, 0, sizeof(int) * (2*N-1));
        memset(DIAGONAL_2, 0, sizeof(int) * (2*N-1));

    } while (std::next_permutation(QUEEN_X_POS.begin(), QUEEN_X_POS.end()));

    return count;
}
