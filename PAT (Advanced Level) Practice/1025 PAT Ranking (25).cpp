#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Stu{
    char registration_number[15];// 不要用long long 前面可能有 0
    int location_number;
    int local_rank;
    int score;
    bool operator < (const Stu & b){
        if(score != b.score)
            return score > b.score;
        else
            return strcmp(registration_number, b.registration_number) < 0;
    }
} stu[30010];
int main(){
    int N, K;
    scanf("%d", &N);
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d", &K);
        for(int j = 0; j < K; j++) {
            scanf("%s %d", stu[cnt + j].registration_number, &stu[cnt + j].score);
            stu[cnt+j].location_number = i;
        }
        sort(stu+cnt, stu+cnt+K);
        stu[cnt].local_rank = 1;
        for(int j = cnt+1; j < cnt+K; j++){
            if(stu[j].score == stu[j-1].score)
                stu[j].local_rank = stu[j-1].local_rank;
            else
                stu[j].local_rank = j - cnt + 1;
        }
        cnt += K;
    }
    sort(stu,stu+cnt);
    int tmp = 1;
    printf("%d\n",cnt);
    printf("%s %d %d %d\n", stu[0].registration_number,tmp,stu[0].location_number,stu[0].local_rank);
    for(int i = 1; i < cnt; i++){
        if(stu[i].score != stu[i-1].score)
            tmp = i+1;
        printf("%s %d %d %d\n", stu[i].registration_number,tmp,stu[i].location_number,stu[i].local_rank);
    }
    return 0;
}