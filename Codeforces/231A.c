// https://codeforces.com/problemset/problem/231/a
#include <stdio.h>

#define MAX_SIZE 1000



int main() {
    int N = 0;
    int A, B, C = 0;
    int S = 0;
    
    scanf("%d", &N);

    while(N > 0) {
        N--;
        scanf("%d %d %d", &A, &B, &C);

        S += (A + B + C >= 2);
    }

    printf("%d", S);
    return 0;
}