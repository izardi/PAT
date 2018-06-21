#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int K;
void add(string t){
    int len = s.length(), carry = 0;
    for(int i = 0; i < len; i++){
        s[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        if(s[i] > '9'){
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry) s += '1';
    reverse(s.begin(), s.end());
}

int main(){
    cin >> s >> K;
    int i;
    for(i = 0; i <= K; i++){
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t || i == K) break;
        add(t);
    }
    cout << s << endl << i;
    return 0;
}