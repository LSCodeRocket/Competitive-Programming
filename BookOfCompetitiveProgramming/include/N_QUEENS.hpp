#define MAX_SIZE 2048
#include <iostream>

int N_QUEENS(int N) {
    int count = 0;

    int QUEENS[MAX_SIZE];
    int BOARD_DATA[MAX_SIZE][MAX_SIZE];


    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            if(BOARD_DATA[y][x] == 1) continue;
            QUEENS[y] = x;
        }
    }
    return count;
}