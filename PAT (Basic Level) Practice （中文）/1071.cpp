#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int T, K;
    scanf("%d %d", &T, &K);
    int n1, b, t, n2;
    while(K--){
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        if(T < t) printf("Not enough tokens.  Total = %d.\n", T);
        else if((n1 < n2 && b) || (n1 > n2 && !b))
            printf("Win %d!  Total = %d.\n", t, T+=t);
        else printf("Lose %d.  Total = %d.\n", t, T-=t);
        if(T <= 0) break;
    }
    if(T <= 0) printf("Game Over.");
    return 0;
}
