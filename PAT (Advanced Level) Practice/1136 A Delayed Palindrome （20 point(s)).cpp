#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindroic(string str){
	for(int i = 0 ; i < str.length()/2; ++i){
		if(str[i] != str[str.length() - 1 - i])
			return false;
	}
	return true;
}
string addString(string & s1, string & s2){
    int l1 = s1.length()-1, l2 = s2.length()-1;
    int flag = 0, n = 0;
    string s = "";
    while(l1 >= 0 && l2 >= 0){
        n = s1[l1] - '0' + s2[l2] - '0' + flag;
        flag = n / 10;
        n %= 10;
        s += '0' + n ;
        --l1;
        --l2;
    }
    while(l1 >= 0){
        n = s1[l1] - '0' + flag;
        flag = n / 10;
        n %= 10;
        s += '0' + n;
        --l1;
    }
    while(l2 >= 0){
        n = s2[l2] - '0' + flag;
        flag = n / 10;
        n %= 10;
        s += '0' + n;
        --l2;
    }
    if(flag != 0)
        s += '0' + flag;
    reverse(s.begin(), s.end());
    return s;
}
int main(){
	// freopen("data.in", "r", stdin);
	int cnt = 0;
	string str, s1, s2;
	cin >> str;
	while(cnt < 10 && !isPalindroic(str)){
		s1 = str;
		reverse(s1.begin(), s1.end());
        s2 = addString(str, s1);
		cout << str << " + " << s1 << " = " << s2 << endl;
		str = s2;
		++cnt;
	}
	if(cnt == 10) printf("Not found in 10 iterations.\n");
	else cout << str << " is a palindromic number." << endl;
	return 0;
}
