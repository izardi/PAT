#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	//freopen("d.in", "r", stdin);
	string s;
	cin >> s;
	int arr[10005] = {0};
	int cntP = 0, cntT = 0;
	vector<int> P, T;

	for(int i = 0; i < s.length(); ++i){
		if(s[i] == 'P')
			++cntP;
		else if(s[i] == 'A'){
			P.push_back(cntP);
		}
	}
	for(int i = s.length(); i >= 0; --i){
		if(s[i] == 'T')
			++cntT;
		else if(s[i] == 'A'){
			T.push_back(cntT);
		}
	}
	long int res = 0;
	for(int i = 0; i < P.size(); ++i){
		res += P[i] * T[P.size()-i-1];
		res %= 1000000007;
	}
	printf("%ld\n", res);
	return 0;
}