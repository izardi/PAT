#include <cstdio>
#include <cstdlib>
long long gcd(long long a, long long b){
	return b == 0 ? abs(a): gcd(b, a%b);
}

int main(){
	// freopen("data.in", "r", stdin);
	int N;
	scanf("%d", &N);
	long long a, b, gcdvalue, numerator = 0, denominator = 1, Integer;
	for(int i = 0; i < N; ++i){
		scanf("%lld/%lld", &a, &b);
		gcdvalue = gcd(a, b);
		a /= gcdvalue;
		b /= gcdvalue;
		numerator = a*denominator + numerator*b;
		denominator = b*denominator;
		gcdvalue = gcd(numerator, denominator);
		numerator /= gcdvalue;
		denominator /= gcdvalue;
	}
	Integer = numerator / denominator;
	numerator %= denominator;
	if(Integer != 0){
		printf("%lld", Integer);
		if(numerator != 0)
			printf(" ");
	}
	if(numerator != 0)
		printf("%lld/%lld", numerator, denominator);
	if(Integer==0 && numerator==0)
		printf("0");
	return 0;
}