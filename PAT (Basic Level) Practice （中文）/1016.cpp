#include <cstdio>

int func(int a, int c){
    int i = 0;
    while(a > 0){
        int x = a % 10;
        a /= 10;
        if(x == c)
            i = i * 10 + c;
    }
    return i;
}
int main(int argc, char *argv[])
{
    int A, DA, B, DB;
    freopen("in", "r", stdin);
    scanf("%d %d %d %d", &A, &DA, &B, &DB);
    printf("%d", func(A, DA) + func(B, DB));
    return 0;
}
