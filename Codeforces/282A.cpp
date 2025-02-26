#include <iostream>
#include <string>
// https://codeforces.com/problemset/problem/282/A

#define MAX_SIZE 4

int main() {
    std::string S;
    int X = 0;
    int N;

    std::cin >> N;
    std::getline(std::cin, S);

    while( N > 0 ) {
        std::getline(std::cin, S);

        X += 2 * (S.find('+') != std::string::npos) - 1;
        N--;
    }

    printf("%d", X);

    return 0;
}