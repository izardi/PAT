#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
    int p[5], solved, sum;
    Node(){
        sum = 0;
        solved = 0;
        for(int i = 0; i < 5; ++i)
            p[i] = -2;
    }
}List[100005];

int id_array[100005];
int hashtab[100005] = {0};

bool cmp(const int &a, const int &b){
    if(List[a].sum != List[b].sum)
        return List[a].sum > List[b].sum;
    else if(List[a].solved != List[b].solved)
        return List[a].solved > List[b].solved;
    else
        return a < b;
}

int main(){
    // freopen("data.in", "r", stdin);

    int p[5] = {0}; 
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    for(int i = 0; i < K; ++i)
        scanf("%d", &p[i]);
    int id, p_id, score, cnt = 0;
    while(M--){
        scanf("%d %d %d", &id, &p_id, &score);
        List[id].p[p_id-1] = max(score, List[id].p[p_id-1]);
        if(score != -1){
            if(!hashtab[id]){
                id_array[cnt++] = id;
                hashtab[id] = 1;
            }
        }
    }
    for(int i = 0; i < cnt; ++i)
        for(int j = 0; j < K; ++j)
            if(List[id_array[i]].p[j] != -1 && List[id_array[i]].p[j] != -2){
                if(List[id_array[i]].p[j] == p[j])
                    List[id_array[i]].solved++;
                List[id_array[i]].sum += List[id_array[i]].p[j];
            }

    sort(id_array, id_array+cnt, cmp);

    int rank = 1, prerank = 1;
    for(int i = 0; i < cnt; ++i){
        if( i != 0 && List[id_array[i]].sum != List[id_array[i-1]].sum)
            prerank = rank;
        printf("%d %05d %d", prerank, id_array[i], List[id_array[i]].sum);

        for(int j = 0; j < K; ++j){
            if(List[id_array[i]].p[j] == -2)
                printf(" -"); 
            else if(List[id_array[i]].p[j] == -1)
                printf(" 0");
            else
                printf(" %d", List[id_array[i]].p[j]);
        }
        printf("\n");
        rank++;
    }
    return 0;
}