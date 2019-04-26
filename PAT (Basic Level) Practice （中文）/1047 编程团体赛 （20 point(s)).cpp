#include <cstdio>

int main(){
	freopen("d.in", "r", stdin);
	int N;
	scanf("%d", &N);
	int arr[1005] = {0};
	int team, mate, score;
	int idx, max = 0;
	while(N--){
		scanf("%d-%d %d", &team, &mate, &score);
		arr[team] += score;
		if(arr[team] > max){
			max = arr[team];
			idx = team;
		}
	}	
	printf("%d %d\n", idx, max);
	return 0;
}