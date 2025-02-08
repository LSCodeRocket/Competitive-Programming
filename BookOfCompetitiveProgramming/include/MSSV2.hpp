#include <iostream>

int MSSV2(int N, int* A) {
    int best = 0;

    for(int a = 0; a < N; a++) {
        int sum = 0;
        for(int b = a; b < N; b++) {
            sum += A[b];
            best = std::max(sum, best);
        }
    }

    return best;

}