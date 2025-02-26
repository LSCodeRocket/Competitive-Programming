#include <iostream>
#include <array>

#define MAX_SIZE 50

// https://codeforces.com/problemset/problem/158/A

int main() {
    int n, k, i, player;
    int W = 0, C = 0, P = 0;

    std::cin >> n;
    std::cin >> k;

    for(i = 0; i < n; i++) {
        std::cin >> player;
        W++;
        if(player != P) {
            C++;

            if(C == k) {break; }

            P = player;
        }
    }
    std::cout << W << "\n";

    return 0;
}