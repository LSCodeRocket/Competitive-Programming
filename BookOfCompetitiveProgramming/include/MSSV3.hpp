#include <iostream>

int MSSV3(int N, int* A) {
    int best = 0;
    int sum = 0;

    for(int i = 0; i < N; i++) {
        sum = std::max(0, sum + A[i]);
        best = std::max(sum, best);
    }

    return best;

}