#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
    int id, sum, d, c, l;
}S[100005];

bool cmp(struct Node a, struct Node b){
    if(a.l != b.l)
        return a.l < b.l;
    else if(a.sum != b.sum)
        return a.sum > b.sum;
    else if(a.d != b.d)
        return a.d > b.d;
    else return a.id < b.id;
}

int main(){
    freopen("in", "r", stdin);
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    int i = 0;
    while(N--){
        scanf("%d %d %d", &S[i].id, &S[i].d, &S[i].c);
        if(S[i].d >= L && S[i].c >= L){
            S[i].sum = S[i].d + S[i].c;
            if(S[i].d >= H && S[i].c >= H) S[i].l = 1;
            else if(S[i].d >= H && S[i].c < H) S[i].l = 2;
            else if(S[i].d >= S[i].c) S[i].l = 3;
            else S[i].l = 4;
            ++i;
        }
    }
    sort(S, S + i, cmp);
    printf("%d\n", i);
    for(int j = 0; j < i; ++j)
        printf("%d %d %d\n", S[j].id, S[j].d, S[j].c);
    return 0;
}
