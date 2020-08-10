#include <cstdio>

int main(int argc, char *argv[])
{
//    freopen("in", "r", stdin);
    int c1, c2;
    scanf("%d %d", &c1, &c2);
    int c3 = c2 - c1;
    int res = int((double)c3 / 100 + 0.5);
    
    printf("%02d:%02d:%02d", res /3600, res%3600/60, res%3600%60);
    return 0;
}
