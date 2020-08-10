#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int G,S,K, g,s,k;
    scanf("%d.%d.%d %d.%d.%d",&G, &S, &K, &g, &s, &k);
    long SUM = long(G)*17*29 + S*29 + K;
    long sum = long(g)*17*29 + s*29 + k;
    long res = sum - SUM;
    if(res < 0){
        res *= -1;
        printf("-");
    }
    printf("%ld.%ld.%ld", res/(17*29), (res%(17*29))/29, (res%(17*29)%29)); 
    return 0;
}
