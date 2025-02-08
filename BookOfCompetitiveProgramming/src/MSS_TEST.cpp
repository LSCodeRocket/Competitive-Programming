#define MAX_ARRAY_SIZE 2048
#include <iostream>
#include <cstdlib>
#include <stdbool.h>
#include <ctime>
#include "../include/MSSV1.hpp"
#include "../include/MSSV2.hpp"
#include "../include/MSSV3.hpp"

void generate_random_array(int N, int* A) {
    for(int i = 0; i < N; i++) {
        A[i] = rand() % 20 - 10;
    }
}


int main() {
    int N;
    int A[MAX_ARRAY_SIZE];

    srand(time(0));

    std::cout << "ARRAY SIZE: ";
    scanf("%d", &N);

    if(N > MAX_ARRAY_SIZE){ std::cout << "Too Big N\n"; }
    while(true){
        generate_random_array(N, A);
        int M_1 = MSSV1(N, A);
        int M_2 = MSSV2(N, A);
        int M_3 = MSSV3(N, A);

        bool B = M_1 == M_2 && M_2 == M_3;
        printf("%d, %d, %d\t", M_1, M_2, M_3);
        std::cout << std::boolalpha << B << std::endl;
        
    }
    return 0;
}