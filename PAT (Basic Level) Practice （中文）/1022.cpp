#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    long c = a + b;
    int i = 0;
    int arr[100];
    do{
        arr[i++] = c % d;
        c /= d;
    }while(c != 0);
    for(--i;i >= 0;--i)
        printf("%d", arr[i]);
    return 0;
}
