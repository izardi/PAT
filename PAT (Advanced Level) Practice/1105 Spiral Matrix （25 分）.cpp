#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(const int a, const int b){
	return a > b;
}

int main(){
	// freopen("data.in", "r", stdin);
	int i, N, data[10005] = {0};
	scanf("%d", &N);
	for(i = 0; i < N; ++i)
		scanf("%d", &data[i]);
	sort(data, data+N, cmp);
	int m, n;
	m = n = (int)sqrt((double)N);
	while(m*n != N){
		if(m*n < N)
			++m;
		else --n;
	}

	int SM[m][n];
	int cnt = 0;
	int level = m / 2 + m % 2;
	for(int i = 0; i < level; ++i){
		for(int j = i; j <= n-1-i && cnt <= N-1; ++j)
			SM[i][j] = data[cnt++];
		for(int j = i+1; j <= m-2-i && cnt <= N-1; ++j)
			SM[j][n-1-i] = data[cnt++];
		for(int j = n-i-1; j >= i && cnt <= N-1; --j)
			SM[m-1-i][j] = data[cnt++];
		for(int j = m-2-i; j>= i+1 && cnt <= N-1; --j)
			SM[j][i] = data[cnt++];
	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(j != 0)
				printf(" ");
			printf("%d", SM[i][j]);
		}
	    printf("\n");
	}
	return 0;
}