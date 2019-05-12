#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int N;
string A, B, ra{"0."}, rb{"0."};

int solve(string & C, string & rc){
	int cnt = 0;
	int pos = C.find('.');
	if(pos == -1) pos = C.length();
	while(cnt < C.length() && (C[cnt] == '0' || C[cnt] == '.')) cnt++;
	if(pos >= cnt) pos -= cnt;
	else pos = pos - cnt + 1;
	if(cnt == C.length())
		pos = 0;
	while((int)rc.length() < (N+2)){
		if(cnt < C.length()){
			if(C[cnt] != '.')
				rc += C[cnt];
			++cnt;
		}
		else rc += '0';
	}
	return pos;
}

int main(){
	//freopen("d.in", "r", stdin);
	scanf("%d ", &N);
	cin >> A >> B;
	int lA{0}, lB{0};
	lA = solve(A, ra);
	lB = solve(B, rb);
	if(lA == lB && ra == rb){
		printf("YES %s*10^%d\n", ra.c_str(), lA);
	}
	else printf("NO %s*10^%d %s*10^%d\n", ra.c_str(), lA, rb.c_str(), lB);
	return 0;
}
