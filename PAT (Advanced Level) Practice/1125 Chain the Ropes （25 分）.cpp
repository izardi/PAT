#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	// freopen("data.in", "r", stdin);
	int N;
	scanf("%d", &N);
	int data[10005] = {0};
	for(int i = 0; i < N; ++i)
		scanf("%d", &data[i]);
	sort(data, data + N);
	double res = data[0];
	for(int i = 1; i < N; ++i)
		res = (res + data[i])/2;
	printf("%d", int(res));
	return 0;
}