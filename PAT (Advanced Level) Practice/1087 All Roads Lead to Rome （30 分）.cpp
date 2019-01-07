#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int INF = 1000000;
int N, K;

map<string, int> city_idx;
map<int, string> idx_name;

int city_happy[205] = {0};
int G[205][205];
int cost[205];
int vis[205] = {0};

vector<int> path[205];
vector<int> tmp_path;
vector<int> res_path;

int max_happy = 0, cnt = 0;
double max_avg_happy = 0;

void DFS(int v){
    tmp_path.push_back(v);
    if(v == 0){
        int cur_happy = 0;
        for(int i = 0; i < tmp_path.size(); ++i){
            cur_happy += city_happy[tmp_path[i]];
        }

        double tmp_avg_happy = 1.0 * cur_happy / (tmp_path.size() - 1);

        if(cur_happy > max_happy){
            max_happy = cur_happy;
            max_avg_happy = tmp_avg_happy;
            res_path = tmp_path;
        } else if(cur_happy == max_happy && tmp_avg_happy > max_avg_happy){
            max_avg_happy = tmp_avg_happy;
            res_path = tmp_path;
        }

        tmp_path.pop_back();
        ++cnt;
        return;
    }

    for(int i = 0; i < path[v].size(); ++i){
        DFS(path[v][i]);
    }

    tmp_path.pop_back();
}

int main(){
    string City1, City2;
    cin >> N >> K >> City1;
    city_idx[City1] = 0;
    idx_name[0] = City1;

    for(int i = 1; i < N; ++i){
        int tmp_happy;
        cin >> City1 >> tmp_happy;
        city_idx[City1] = i;
        idx_name[i] = City1;
        city_happy[i] = tmp_happy;
    }

// fill G , cost
    for(int i = 0; i < 205; ++i){
        fill(G[i], G[i] + 205, INF);
    }
    fill(cost, cost + 205, INF);

    for(int i = 0; i < K; ++i){
        int tmp_cost;
        cin >> City1 >> City2 >> tmp_cost;
        G[city_idx[City1]][city_idx[City2]] = G[city_idx[City2]][city_idx[City1]] = tmp_cost;
    }
    cost[0] = 0;

    for(int i = 0; i < N; ++i){
        int u = -1, min = INF;
        for(int j = 0; j < N; ++j){
            if(!vis[j] && cost[j] < min){
                min = cost[j];
                u = j;
            }
        }
        if(u == -1)
            break;
        vis[u] = 1;
        for(int j = 0; j < N; ++j){
            if(!vis[j]){
                if(G[u][j] + cost[u] < cost[j]){
                    cost[j] = cost[u] + G[u][j];
                    path[j].clear();
                    path[j].push_back(u);
                }
                else if(G[u][j] + cost[u] == cost[j])
                    path[j].push_back(u);
            }
        }
    }

    DFS(city_idx["ROM"]);

    printf("%d %d %d %d\n", cnt, cost[city_idx["ROM"]], max_happy, (int)max_avg_happy);
    for(int i = res_path.size() - 1; i >= 1; --i){
        cout << idx_name[res_path[i]] << "->";
    }

    printf("ROM");
    return 0;
}