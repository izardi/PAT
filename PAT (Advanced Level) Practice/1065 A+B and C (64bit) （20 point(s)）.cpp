#include <cstdio>

int main(){
	// freopen("data.in", "r", stdin);
	int T;
	scanf("%d", &T);
	long long A, B, C, SUM;
	
	for(int i = 1; i <= T; ++i){
		scanf("%lld %lld %lld", &A, &B, &C);
		SUM = A + B;
		printf("Case #%d: ", i);
		
		if(A > 0 && B > 0 && SUM < 0)
			printf("true");
		else if(A < 0 && B < 0 && SUM >= 0)
			printf("false");
		else if(SUM > C)
			printf("true");
		else
			printf("false");
		printf("\n");
	}
	return 0;
}