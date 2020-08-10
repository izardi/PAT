#include <cstdio>
#include <cstring>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int A, B;
    scanf("%d %d", &A, &B);
    char s[10];
    A *= B;
    sprintf(s, "%d", A);
    int i = strlen(s) - 1;
    while(s[i] == '0') --i;
    for(; i >= 0; --i)
        printf("%c", s[i]);
    return 0;
}
