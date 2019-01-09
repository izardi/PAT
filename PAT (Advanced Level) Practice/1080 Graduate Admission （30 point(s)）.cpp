#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int GE, sum, id;
    int choice[5];
} List[40005];

struct School{
    int quota;
    vector<int> admits;
} Sch[105];

bool cmp(const struct Node &a, const struct Node &b){
    if(a.sum != b.sum)
        return a.sum > b.sum;
    return a.GE > b.GE;
}
bool cmp2(int &a, int &b){
    return List[a].id < List[b].id;
}
int main(){
    // freopen("data.in", "r", stdin);
    int N, M, K, i, j, tmp;
    scanf("%d %d %d", &N, &M, &K);
    for(i = 0; i < M; ++i)
        scanf("%d", &Sch[i].quota);

    for(i = 0; i < N; ++i){
        List[i].id = i;
        scanf("%d %d", &List[i].GE, &tmp);
        List[i].sum = List[i].GE + tmp;
        for(j = 0; j < K; ++j)
            scanf("%d", &List[i].choice[j]);
    }
    sort(List, List + N, cmp);

    for(i = 0; i < N; ++i){
        for(j = 0; j < K; ++j) {
            tmp = List[i].choice[j];
            int las = 0;
            if(Sch[tmp].admits.size() != 0)
                las = *(Sch[tmp].admits.end()-1);
            if ( (Sch[tmp].admits.size() < Sch[tmp].quota) || ( (List[i].sum == List[las].sum) && (List[i].GE == List[las].GE) ) ) {
                Sch[tmp].admits.push_back(i);
                break;
            }
        }
    }
    for(i = 0; i < M; ++i){
        int flag = 0;
        sort(Sch[i].admits.begin(), Sch[i].admits.end(), cmp2);
        for (int &admit : Sch[i].admits) {
            if(flag) printf(" ");
            printf("%d", List[admit].id);
            flag = 1;
        }
        printf("\n");
    }
    return 0;
}