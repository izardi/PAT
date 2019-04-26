#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int main(){
	// freopen("d.in", "r", stdin);
	string s1, s2;
	cin >> s1 >> s2;
	map<char, int> mp;
	for(int i = 0; i < s1.length(); ++i){
		mp[s1[i]]++;
	}
	int cnt = 0;
	for(int i = 0; i < s2.length(); ++i){
		if(mp[s2[i]] == 0)
			++cnt;
		else --mp[s2[i]];
	}
	if(cnt == 0) printf("Yes %d\n", s1.length() - s2.length());
	else printf("No %d\n", cnt);
	return 0;
}