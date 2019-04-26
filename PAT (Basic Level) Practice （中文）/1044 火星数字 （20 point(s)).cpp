#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

char G[][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char S[][4] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main(){
	//freopen("d.in", "r", stdin);
	int N;
	scanf("%d\n", &N);
	string s;
	while(N--){
		getline(cin, s);
		if(isdigit(s[0])){
			int tmp = stoi(s);
			int flag = 0;
			if(tmp == 0){ 
				printf("tret");
			}
			else if(tmp > 12){
				printf("%s", S[tmp/13]);
				flag = 1;
			}
			if(tmp%13 != 0){
				if(flag) printf(" ");
				printf("%s", G[tmp%13]);
			}
		}
		else{
			int res = 0;
			if(s.length() == 4){
				res = 0;
			}
			else if(s.length() > 3){
				for(int i = 0; i < 13; ++i)
					if(s.substr(0, 3) == S[i]){
						res += i*13;
						break;
					}
				s = s.substr(4, 3);
			}
			for(int i = 0; i < 13; ++i){
				if(s == S[i]){
					res += i*13;
					break;
				}
				if(s == G[i]){
					res += i;
					break;
				}
			}
			printf("%d", res);
		}
		printf("\n");
	}
	return 0;
}