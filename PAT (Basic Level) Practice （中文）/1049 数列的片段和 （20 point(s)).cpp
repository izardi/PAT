#include <cstdio>

int main(){
	//freopen("d.in", "r", stdin);
	double arr[100006];
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%lf", &arr[i]);
	double res;
	for(int i = 0; i < N; ++i){
		res += arr[i]*(i+1)*(N-i);
	}	
	printf("%.2lf", res);
	return 0;
}