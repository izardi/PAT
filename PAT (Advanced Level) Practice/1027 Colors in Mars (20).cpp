#include <cstdio>

int main(){
    int R, G, B;
    scanf("%d %d %d", &R, &G, &B);
    char key[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    printf("#");
    printf("%c%c%c%c%c%c",key[R/13],key[R%13],key[G/13],key[G%13],key[B/13],key[B%13]);
    return 0;
}