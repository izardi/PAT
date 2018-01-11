#include <stdio.h>
#include <math.h>

int main() {
    int n;
    char c;
    scanf("%d %c", &n, &c);

    int row = (int)sqrt(n);

    for(int i = row; i > 0; i--){
        for(int k = row; k < i; k--){
            printf(" ");
        }
        for(int j = 2*i-1; j > 0; j--){
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}
