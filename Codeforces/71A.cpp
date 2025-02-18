#include <iostream>
#include <array>
#include <string>

#define MAX_SIZE 100
// https://codeforces.com/problemset/problem/71/A



int main() {
    int i;
    int count;
    int length;
    std::array<std::string, MAX_SIZE> preabbreviated;

    std::cin >> count;
    std::getline(std::cin, preabbreviated[0]);

    if(count > MAX_SIZE) { return 1; }

    for(i = 0; i < count; i++) {
        std::getline(std::cin, preabbreviated[i]);
    }

    for(i = 0; i < count; i++) {
        length = preabbreviated[i].length();

        if(length > 10) {
            std::cout << preabbreviated[i][0] << length-2 << preabbreviated[i][length-1] << "\n";
            continue;
        }
        std::cout << preabbreviated[i] << "\n";

    }
    
    return 0;
}