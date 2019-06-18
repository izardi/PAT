#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;

struct Node{
    int Mestate, Marea; 
}Stu[10000];

struct RNode{
    int cnt;
    double AVGsets, AVGarea;
    RNode(){
        cnt = AVGsets = AVGarea = 0; 
    }
}Rnode[10000];

int ST[10000] = {0};
int vis[10000] = {0};

int findFather(int idx){
    while(ST[idx] != idx) idx = ST[idx];
    return idx;
}

void Union(int a, int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa < fb)
        ST[fb] = fa;
    else if( fa > fb)
        ST[fa] = fb; 
}

bool cmp(int a, int b){
    if(Rnode[a].AVGarea != Rnode[b].AVGarea)
        return Rnode[a].AVGarea > Rnode[b].AVGarea;
    return a < b; // 这一步多余，因为asn中就是按照id的顺序进入的
}

int main(){
    //freopen("d.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for(int i = 0; i < 10000; ++i)
        ST[i] = i;
    int K, id, F, M, idx;
    map<int, bool> mp; 
    for(int i = 0; i < N; ++i){
        scanf("%d %d %d %d", &id, &F, &M, &K);
        mp[id] = true;
        vis[id] = 1;
        if(F != -1 ){
            Union(id, F);
            vis[F] = 1;
        }
        if( M != -1){
            Union(id, M);
            vis[M] = 1;
        }
        for(int j = 0; j < K; ++j){
            scanf("%d", &idx);
            Union(id, idx);
            vis[idx] = 1;
        }
        scanf("%d %d", &Stu[id].Mestate, &Stu[id].Marea);
    }

    vector<int> ans;
    for(int i = 0; i < 10000; ++i)
        if(vis[i]){
            int father = findFather(i);
            Rnode[father].cnt++;
            if(mp[i]){
                Rnode[father].AVGarea += Stu[i].Marea;
                Rnode[father].AVGsets += Stu[i].Mestate;
            }
            if(ST[i] == i)
                ans.push_back(i);
        }
    printf("%d\n", ans.size());
    for(auto it = ans.begin(); it != ans.end(); ++it){
        Rnode[*it].AVGarea /= Rnode[*it].cnt;
        Rnode[*it].AVGsets /= Rnode[*it].cnt;
    }
    sort(ans.begin(), ans.end(), cmp);
    for(auto it = ans.begin(); it != ans.end(); ++it){
        printf("%04d %d %.3lf %.3lf\n", *it, Rnode[*it].cnt, Rnode[*it].AVGsets, Rnode[*it].AVGarea); 
    }
    return 0;
}