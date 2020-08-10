#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int arr[10] = {0};
    char c;
    while(scanf("%c", &c) != EOF)
        ++arr[c-'0'];
    for(int i = 0; i < 10; ++i)
        if(arr[i] !=0)
            printf("%d:%d\n",i, arr[i]);
    return 0;
}
