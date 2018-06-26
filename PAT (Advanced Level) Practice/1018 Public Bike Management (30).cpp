#include <cstdio>
#include <vector>
using namespace std;

const int INF = 10000000;
int capacity, num_s, idx_p, roads;
int curr_num[510] = {0};
int G[510][510];
bool vis[510] = {false};
vector<int> path, temppath;
int minback = INF, minsend = INF, mindis = INF;

void dfs(int v, int tempsend, int tempback, int tempdis){
	temppath.push_back(v);
	vis[v] = true;
	if(v == idx_p){
		if(mindis > tempdis){
			mindis = tempdis;
			minback = tempback;
			minsend = tempsend;
			path = temppath;
		}
		else if( mindis == tempdis ){
			if(minsend > tempsend){
				minsend = tempsend;
				minback = tempback;
				path = temppath;
			}
			else if( minsend == tempsend && minback > tempback){
				minback = tempback;
				path = temppath;
			}
		}
		return;
	}
	for(int i = 1; i <= num_s; i++){
		if(!vis[i] && G[v][i] != INF){
			int temp = curr_num[i] - capacity;
			int tempb = tempback, temps = tempsend;
			if(temp >= 0)
				tempb += temp;
			else{
				if(tempback + temp < 0){
					temps -= (tempback + temp);
					tempb = 0;
				}
				else
					tempb += temp;
			}
			dfs(i, temps, tempb, tempdis + G[v][i]);
			temppath.pop_back();
			vis[i] = false;
		}
	}
}

int main(){
	scanf("%d %d %d %d", &capacity, &num_s, &idx_p, &roads);
	capacity /= 2;
	for(int i = 1; i <= num_s; i++){
		scanf("%d", &curr_num[i]);
		for(int j = 0; j <= num_s; j++)
			G[i][j] = INF;
	}
	for(int i = 0; i <= num_s; i++)
		G[0][i] = INF;
	int x, y;
	
	for(int i = 0; i < roads; i++){
		scanf("%d %d", &x, &y);
		scanf("%d", &G[x][y]);
		G[y][x] = G[x][y];
	}
	dfs(0, 0, 0, 0);
	printf("%d ", minsend);
	for(int i = 0; i < path.size(); i++){
		if( i != 0)
			printf("->");
		printf("%d", path[i]);
	}
	printf(" %d", minback);
	return 0;
}