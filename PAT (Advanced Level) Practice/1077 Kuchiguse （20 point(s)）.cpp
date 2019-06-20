#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    // freopen("data.in", "r", stdin);
    int N, i, j;
    scanf("%d\n", &N);
    string ans;

    for(i = 0; i < N; ++i){
        string s;
        getline(cin, s);
        reverse(s.begin(), s.end());
        if(i == 0)
            ans = s;
        else{
            int ml = s.length() < ans.length() ? s.length() : ans.length();
            for(j = 0; j < ml && s[j] == ans[j]; ++j);
            ans = ans.substr(0, j);
        }
    }

    reverse(ans.begin(), ans.end());
    if(ans.length() == 0) printf("nai");
    else printf("%s", ans.c_str());
    return 0;
}