#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
    int id;
    int score[4], rank[4];
    int best;
} Stu[2001];

int exist[1000000] = {0};
int flag;
int cmp(node a, node b){ return a.score[flag] > b.score[flag]; }

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d", &Stu[i].id, &Stu[i].score[1], &Stu[i].score[2], &Stu[i].score[3]);
        Stu[i].score[0] = (Stu[i].score[1]+Stu[i].score[2]+Stu[i].score[3])/3.0 + 0.5;
    }
    for(flag = 0; flag < 4; flag++){
        sort(Stu, Stu+N, cmp);
        Stu[0].rank[flag] = 1;
        for(int i = 1; i < N; i++){
            Stu[i].rank[flag] = i+1;
            if(Stu[i-1].score[flag] == Stu[i].score[flag])
                Stu[i].rank[flag] = Stu[i-1].rank[flag];
        }
    }
    for(int i = 0; i < N; i++){
        exist[Stu[i].id] = i+1;
        int minn = Stu[i].rank[0];
        Stu[i].best = 0;
        for(int j = 1; j < 4; j++){
            if(minn > Stu[i].rank[j]){
                minn = Stu[i].rank[j];
                Stu[i].best = j;
            }
        }
    }
    char c[4] = {'A', 'C', 'M', 'E'};
    int id, tmp;
    for(int i = 0; i < M; i++){
        scanf("%d", &id);
        tmp = exist[id];
        if(tmp)
            printf("%d %c\n", Stu[tmp-1].rank[Stu[tmp-1].best], c[Stu[tmp-1].best]);
        else
            printf("N/A\n");
    }
    return 0;
}
