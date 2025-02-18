#include <stdio.h>

int main() {
    int w = 0;
    char outputs[2][4] = {"YES", "NO"};

    if(!scanf("%d", &w)) { return 1; }

    printf("%s\n", outputs[!(w % 2 == 0 && w > 2)]);

    return 0;
}