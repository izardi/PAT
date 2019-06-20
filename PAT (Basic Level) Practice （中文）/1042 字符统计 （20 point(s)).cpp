#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    //freopen("d.in", "r", stdin);
    string s;
    int ht[128] = {0};
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(int i = 0; i < s.size(); ++i)
        ++ht[s[i]];
    int m = 0;
    char c;
    for(int i = 'a'; i < 'z'; ++i){
        if(m < ht[i]){
            c = i;
            m = ht[i];
        }
    }
    printf("%c %d\n", c, m);
}