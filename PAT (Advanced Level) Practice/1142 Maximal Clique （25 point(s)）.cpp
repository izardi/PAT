#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int Nv, Ne;
int G[201][201];

int main(){
//    freopen("data.in", "r", stdin);
    fill(G[0], G[0]+201*201, 0);
    scanf("%d %d", &Nv, &Ne);
    int v1, v2;
    for(int i = 0; i < Ne; ++i){
        scanf("%d %d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;
    }
    int M, K, tmp[201];
    scanf("%d", &M);
    while(M--){
        int flag = 1;
        int vis[201] = {0};
        scanf("%d", &K);
        for(int i = 0; i < K; ++i){
            scanf("%d", &tmp[i]);
            vis[tmp[i]] =1;
        }
        for(int i = 0; i < K; ++i){
            for(int j = i+1; j < K; ++j){
                if(G[tmp[i]][tmp[j]] != 1){
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag) printf("Not a Clique\n");
        else{
            for(int i = 1; i <= Nv; ++i){
                if(!vis[i]){
                    int j;
                    for(j = 0; j < K; ++j)
                        if(G[tmp[j]][i] == 0)
                            break;
                    if(j == K){
                        flag = 2;
                        break;
                    }
                }
            }
            if(flag == 2) printf("Not Maximal\n");
            else printf("Yes\n");
        }
    }
    return 0;
}
