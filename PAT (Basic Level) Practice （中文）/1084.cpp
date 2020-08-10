#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    string s;
    cin >> s >> N;
    int i, j;
    while(--N){
        string tmp;
        for(i = 0; i < s.length(); i = j){
            for(j = i; j < s.length() && s[j] == s[i]; ++j);
            tmp += s[i] + to_string(j - i);
        }
        s = tmp;
    }
    cout << s;
    return 0;
}
