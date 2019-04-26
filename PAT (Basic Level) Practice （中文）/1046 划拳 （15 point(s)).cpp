#include <cstdio>

int main(){
	// freopen("d.in", "r", stdin);
	int N;
	scanf("%d", &N);
	int A, a, B, b;
	int cntA = 0, cntB = 0;
	while(N--){
		scanf("%d %d %d %d", &A, &a, &B, &b);
		if((a == (A+B)) && (b != (A+B)))
			cntB++;
		else if((a != (A+B)) && (b==(A+B)))
			cntA++;
	}
	printf("%d %d\n", cntA, cntB);
	return 0;
}