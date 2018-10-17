#include <map>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

int main(){
    string s, tmp;
    getline(cin, s);
    map<string, int> mp;
    for(int i = 0; i < s.length(); ++i){
        if(isalnum(s[i])){
            s[i] = tolower(s[i]);
            tmp += s[i];
        }
        if(!isalnum(s[i]) || i == s.length() - 1){
            if(tmp.length()) ++mp[tmp];
            tmp = "";
        }
    }
    int ans = 0;
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
        if(it->second > ans){
            tmp = it->first;
            ans = it->second;
        }
    }
    cout << tmp << " " << ans;
    return 0;
}