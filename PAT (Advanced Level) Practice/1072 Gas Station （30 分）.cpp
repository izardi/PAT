#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int G[1020][1020];
int dist[1020];
int vis[1020];
const int INF = 9999999;
int N, M, K, R;

int main(){
    fill(G[0], G[0] + 1020*1020, INF);
    scanf("%d%d%d%d", &N, &M, &K, &R);
    string s1, s2;
    int tmp;

    for(int i = 0; i < K; ++i){
        cin >> s1 >> s2 >> tmp;
        int a, b;
        if(s1[0] == 'G'){
            s1 = s1.substr(1);
            a = N + stoi(s1);
        } 
        else a = stoi(s1);
        if(s2[0] == 'G') {
            s2 = s2.substr(1);
            b = N + stoi(s2);
        }
        else b = stoi(s2);
        G[a][b] = G[b][a] = tmp;
    }

    int ansid = -1;
    double ansres, ansdis;
    for(int idx = N + 1; idx <= N+M; ++idx){
        fill(dist, dist + 1020, INF);
        fill(vis, vis + 1020, 0);
        dist[idx] = 0;
    
        for(int i = 1; i <= N+M; ++i){
            int min = INF, idx = 0;
            for(int j = 1; j <= N+M; ++j){
            if(!vis[j] && dist[j] < min){
                idx = j;
                min = dist[j];
            } 
            }
            if(!idx) break;
            vis[idx] = 1;
            for(int j = 1; j <= N + M; ++j){
                if(!vis[j] && dist[idx] + G[idx][j] < dist[j])
                    dist[j] = dist[idx] + G[idx][j]; 
            } 
        }

        int res = 0, mindis = INF;
        for(int i = 1; i <= N; ++i){
            if(dist[i] > R){
                mindis = -1;
                break;
            }
            if(dist[i] < mindis) mindis = dist[i];
            res += dist[i];
        }

        if(mindis == -1) continue;
        if(mindis > ansdis){
            ansid = idx;
            ansdis = mindis;
            ansres = res;
        }
        else if(mindis == ansdis && ansres > res){
            ansres = res;
            ansid = idx;
        }
    }
    if(ansid == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", ansid-N, ansdis, ansres/N);
    return 0;
}