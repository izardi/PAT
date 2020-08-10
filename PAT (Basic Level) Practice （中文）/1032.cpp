#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int total[100005] = {0};
    int maxidx = 0;
    int id, score;
    while(N--){
        scanf("%d %d", &id, &score);
        total[id] += score;
        if(total[id] > total[maxidx])
            maxidx = id;
    }
    printf("%d %d", maxidx, total[maxidx]);
    return 0;
}
