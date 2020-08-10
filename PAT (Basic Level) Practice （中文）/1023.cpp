#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int arr[10];
    for(int i = 0; i < 10; ++i)
        scanf("%d", &arr[i]);
    int i = 0;
    while(arr[++i] == 0);
    --arr[i];
    printf("%d", i);
    for(int i = 0; i < 10; ++i)
        while(arr[i]){
            printf("%d", i);
            --arr[i];
        }
    return 0;
}
