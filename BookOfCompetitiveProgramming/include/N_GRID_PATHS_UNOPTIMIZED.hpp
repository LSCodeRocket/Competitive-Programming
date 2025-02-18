#define MAX_GRID_SIZE 400

#define DEBUG 0

#include <iostream>
#include <set>

int NEXT_DIRECTION(int x, int y, int x_p, int y_p, int* count, std::set<int>* path, int N) {

    (*path).insert(x + N*y);

    if(DEBUG) {
        std::cout << "PATH : ";
        for(auto x : (*path)) {
            std::cout << x << ", ";
        }

        std::cout << std::endl;
    }

    bool isOnLastSquare = x == N - 1 && y == N - 1;

    if( isOnLastSquare && (*path).size() >= N * N ) {
        
        (*count)++; 

        if(DEBUG) { 
            std::cout << "[-] (" << N << ") COUNT IS NOW " << (*count) << "\n";
            std::cout << "[!] DOES PATH CONTAIN LAST -> " << (*path).count(N * N - 1) << "\n";
        }

        return *count; 
    }


    bool isOnLeftEdge = x == 0;
    bool isOnRightEdge = x == N - 1;
    bool isOnTopEdge = y == 0;
    bool isOnBottomEdge = y == N - 1;


    bool isLeftTaken = (*path).find(x - 1 + (N * y)) != (*path).end();
    bool isRightTaken = (*path).find(x + 1 + (N * y)) != (*path).end();
    bool isTopTaken = (*path).find(x  + (N * (y - 1))) != (*path).end();
    bool isBottomTaken = (*path).find(x  + (N * (y + 1))) != (*path).end();

    if(DEBUG) {
        std::cout << "[+] EDGES : " << isOnLeftEdge << " " << isOnRightEdge << " " << isOnTopEdge << " " << isOnBottomEdge << std::endl;
    }

    if(DEBUG) {
        std::cout << "[+] TAKEN_PATH : " << isLeftTaken << " " << isRightTaken << " " << isTopTaken << " " << isBottomTaken << std::endl;
    }


    if(!isOnLeftEdge && !isLeftTaken) { NEXT_DIRECTION(x - 1, y, x, y, count, path, N); (*path).erase(x - 1 + N * y); }
    if(!isOnRightEdge && !isRightTaken) { NEXT_DIRECTION(x + 1, y, x, y, count, path, N); (*path).erase(x + 1 + N * y);}
    if(!isOnTopEdge && !isTopTaken) { NEXT_DIRECTION(x, y - 1, x, y, count, path, N); (*path).erase(x + N * (y - 1)); }
    if(!isOnBottomEdge && !isBottomTaken) { NEXT_DIRECTION(x, y + 1, x, y, count, path, N); (*path).erase(x + N * (y + 1));}

    return *count;
}

int N_GRID_PATHS(int N) {
    int count = 0;
    std::set<int> path;

    if(N * N >= MAX_GRID_SIZE){ perror("[!] N IS TOO LARGE!"); return -1; }

    return NEXT_DIRECTION(0, 0, 0, 0, &count, &path, N);
}