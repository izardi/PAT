#include <cstdio>
#include <cstring>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int a, b;
    scanf("%d %d", &a, &b);
    a += b;
    char s[100];
    if(a < 0){ printf("-"); a*= -1; }
    sprintf(s, "%d", a);
    int len = strlen(s);
    for(int i = 0; i < len; ++i){
        if((len-i) % 3 == 0 && i != 0)
            printf(",");
        printf("%c", s[i]);
    }
    return 0;
}
