#define MAX_GRID_SIZE 400

#define DEBUG 0

#include <iostream>

int NEXT_DIRECTION(int x, int y, int x_p, int y_p, int* count, int* path, int path_length, int N) {

    path[x + N * y] = 1;

    if(DEBUG) {
        std::cout << "PATH : ";
        for(int i = 0; i < N * N + 1; i++) {
            std::cout << path[i] << ", ";
        }

        std::cout << std::endl;
    }

    bool isOnLastSquare = x == N - 1 && y == N - 1;

    if( isOnLastSquare && path_length >= N * N ) {
        
        (*count)++; 

        if(DEBUG) { 
            std::cout << "[-] (" << N << ") COUNT IS NOW " << (*count) << "\n";
            std::cout << "[!] DOES PATH CONTAIN LAST -> " << path[x + N*y] << "\n";
        }

        return *count; 
    }
    // OPTIMIZATION 2 - REACHING LAST SQUARE PREMATURELY -> RECURSIVE CALLS END
    else if (isOnLastSquare) {
        return *count;
    }


    bool isOnLeftEdge = x == 0;
    bool isOnRightEdge = x == N - 1;
    bool isOnTopEdge = y == 0;
    bool isOnBottomEdge = y == N - 1;

    bool isPreviousStateLeft = x - x_p >= 1;
    bool isPreviousStateRight = x - x_p <= 1;
    bool isPreviousStateTop = y - y_p >= 1;
    bool isPreviousStateBottom = y - y_p <= 1;

    bool isLeftTaken = path[x - 1 + N * y] == 1;
    bool isRightTaken = path[x + 1 + N * y] == 1;
    bool isTopTaken = path[x + N * (y - 1)] == 1;
    bool isBottomTaken = path[x + N * (y + 1)] == 1;

    if(DEBUG) {
        std::cout << "[+] EDGES : " << isOnLeftEdge << " " << isOnRightEdge << " " << isOnTopEdge << " " << isOnBottomEdge << std::endl;
    }

    if(DEBUG) {
        std::cout << "[+] TAKEN_PATH : " << isLeftTaken << " " << isRightTaken << " " << isTopTaken << " " << isBottomTaken << std::endl;
    }

    // OPTIMIZATION 1 - ALWAYS GO DOWN FIRST THEN MULTIPLY RESULTS BY 2
    if(x == 0 && y == 0 ) { NEXT_DIRECTION(x, y + 1, x, y, count, path, path_length + 1, N); (*count) *= 2; return (*count); }

    // OPTIMIZATION 3 & 4 - If the path touches a wall / a part of the path, and to either side they're empty -> end recursive calls
    bool isPathSplitLeft = (( isLeftTaken && !isPreviousStateLeft ) || isOnLeftEdge) && ( (!isTopTaken && !isOnTopEdge) && (!isBottomTaken && !isOnBottomEdge) );
    bool isPathSplitRight = (( isRightTaken && !isPreviousStateRight) || isOnRightEdge) && ( (!isTopTaken && !isOnTopEdge) && (!isBottomTaken && !isOnBottomEdge) );
    bool isPathSplitTop = (( isTopTaken && !isPreviousStateTop ) || isOnTopEdge) && ( (!isLeftTaken && !isOnLeftEdge) && (!isRightTaken && !isOnRightEdge) );
    bool isPathSplitBottom = (( isBottomTaken && !isPreviousStateBottom ) || isOnBottomEdge) && ( (!isLeftTaken && !isOnLeftEdge) && (!isRightTaken && !isOnRightEdge) );

    if(isPathSplitBottom || isPathSplitLeft || isPathSplitRight || isPathSplitTop) { return *count; }

    if(!isOnLeftEdge && !isLeftTaken) { NEXT_DIRECTION(x - 1, y, x, y, count, path, path_length + 1, N); path[x - 1 + N * y] = 0; }
    if(!isOnRightEdge && !isRightTaken) { NEXT_DIRECTION(x + 1, y, x, y, count, path, path_length + 1, N); path[x + 1 + N * y] = 0; }
    if(!isOnTopEdge && !isTopTaken) { NEXT_DIRECTION(x, y - 1, x, y, count, path, path_length + 1, N); path[x + N * (y - 1)] = 0;  }
    if(!isOnBottomEdge && !isBottomTaken) { NEXT_DIRECTION(x, y + 1, x, y, count, path, path_length + 1, N); path[x + N * (y + 1)] = 0; }

    return *count;
}

int N_GRID_PATHS(int N) {
    int count = 0;
    int path[MAX_GRID_SIZE] = {0};

    if((N + 1) * N >= MAX_GRID_SIZE){ perror("[!] N IS TOO LARGE!"); return -1; }

    return NEXT_DIRECTION(0, 0, 0, 0, &count, path, 1, N);
}