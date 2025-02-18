#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <string>
#include <set>
#include <array>
#include <map>

void DYNAMIC_ARRAY_TEST(int N) {

    std::vector<int> A(N, 4);


    std::cout << "PRINTING USING AUTO" << std::endl;

    for(auto a : A) {
        std::cout << a << std::endl;
    }

    
    for(int i = 0; i < N; i++) {
        A.push_back(rand() % 255 - 128);
    }

    std::cout << "PRINTING USING A.size()" << std::endl;

    for(int i = 0; i < A.size(); i++) {
        std::cout << A[i] << std::endl;
    }

    std::cout << "POP BACK TEST " << std::endl;

    std::cout << A.back() << std::endl;
    
    A.pop_back();

    std::cout << A.back() << std::endl;

}

void SET_TEST(int N) {

    std::set<int> A;


    
    for(int i = 0; i < N; i++) {
        A.insert(rand() % 255 - 128);
    }


    std::cout << "PRINTING USING AUTO" << std::endl;

    for(auto a : A) {
        std::cout << a << std::endl;
    }

}


void MAP_TEST(int N) {
    std::map<std::string, int> M; 
    
}