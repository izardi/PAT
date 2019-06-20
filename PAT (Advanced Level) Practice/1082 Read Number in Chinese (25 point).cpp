#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char num[][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char uni[][5] = {"", "Shi", "Bai", "Qian"};

int main(){
	//freopen("d.txt", "r", stdin);
	int n;
	scanf("%d", &n); //不超过9位数
	if( n < 0 ){ printf("Fu "); n *= -1; }
	if(n == 0){ printf("ling"); return 0;}
	string str = to_string(n);
	int N[10];
	int len = str.length();
	for(int i = 0; i < len; ++i)
		N[i] = str[i]-'0';

	int pre = 0, first = 1;
	for(int i = 0; i < len; ++i){
		if(N[i] == 0)
			pre = 1;
		else{
			if(pre == 1){
				printf(" ling");
				pre = 0;
			}
			if(first){
				printf("%s", num[N[i]]);
				first = 0;
			} else printf(" %s", num[N[i]]);
			if((len-i-1)%4!=0)
				printf(" %s", uni[(len-1-i)%4]);
		}	
		if(len - i == 9) printf(" Yi");
		if(len - i == 5) printf(" Wan");
	}
	return 0;
}
