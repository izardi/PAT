#include <cstdio>
#include <algorithm>

using namespace std;

int N, L, H;

struct Node{
    int id, virtue, sum, level;
};

bool cmp(const Node &a, const Node &b){
    if(a.level != b.level)
        return a.level < b.level;
    else if ( a.sum != b.sum )
        return a.sum > b.sum;
    else if( a.virtue != b.virtue)
        return a.virtue > b.virtue;
    else return a.id < b.id;
}

int main(){
    // freopen("data.in", "r", stdin);
    struct Node pList[100005];
    scanf("%d %d %d", &N, &L, &H);
    int cnt = 0;
    int talent = 0;
    for(int i = 0; i < N; ++i){
        scanf("%d %d %d", &pList[cnt].id, &pList[cnt].virtue, &talent);
        if(pList[cnt].virtue >= L && talent >= L){
            pList[cnt].sum = pList[cnt].virtue + talent;
            
            if(pList[cnt].virtue >= H && talent >= H)
                pList[cnt].level = 1;
            else if(pList[cnt].virtue >= H)
                pList[cnt].level = 2;
            else if(pList[cnt].virtue >= talent)
                pList[cnt].level = 3;
            else pList[cnt].level = 4;
            
            ++cnt;
        }
    }
    sort(pList, pList+cnt, cmp);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; ++i)
        printf("%d %d %d\n", pList[i].id, pList[i].virtue, pList[i].sum - pList[i].virtue);
    return 0;
}