#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int id, tmp, score;
    int hash[1005] = {0};

    int mi = 0;
    while(N--){
        scanf("%d-%d %d", &id, &tmp, &score);
        hash[id] += score;
        if(hash[mi] < hash[id])  
            mi = id;
    }
    printf("%d %d", mi, hash[mi]);
    return 0;
}
