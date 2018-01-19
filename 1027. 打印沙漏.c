#include <stdio.h>
#include <math.h>

int main() {
    int n;
    char c;
    scanf("%d %c", &n, &c);

    int row = (int)sqrt((n+1)/2);

    for(int i = row; i > 0; i--){
        for(int k = row; k > i; k--){
            printf(" ");
        }
        for(int j = 2*i-1; j > 0; j--){
            printf("%c", c);
        }
        printf("\n");
    }

    for(int i = 1; i < row; i++){
        for(int k = i+1; k < row; k++){
            printf(" ");
        }
        for(int j = 2*i+1; j > 0; j--){
            printf("%c", c);
        }
        printf("\n");
    }
    int tmp = n-2*row*row+1;
    printf("%d", tmp);
    return 0;
}