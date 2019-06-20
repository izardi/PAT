#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    // freopen("d.in", "r", stdin);
    string s;
    cin >> s;
    map<char, int> mp;
    mp['P'] = 1; mp['A'] = 2; mp['T'] = 3;
    mp['e'] = 4; mp['s'] = 5; mp['t'] = 6;
    int arr[7] = {0};
    for(int i = 0; i < s.length(); ++i)
        ++arr[mp[s[i]]];
    char c[] = " PATest";
    while(true){
        int flag = 1;
        for(int i = 1; i <= 6; ++i){
            if(arr[i]){ 
                --arr[i];
                printf("%c", c[i]);
                flag = 0;
            }
        }
        if(flag) break;
    }
    return 0;
}