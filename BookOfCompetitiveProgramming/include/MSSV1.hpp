#include <iostream>

int MSSV1(int N, int* A) {
    int best = 0;

    for(int a = 0; a < N; a++) {
        for(int b = 0; b < N; b++) {

            int sum = 0;

            for(int k = a; k <= b; k++) {
                sum += A[k];
            }

            best = std::max(sum, best);

        }
    }

    return best;

}