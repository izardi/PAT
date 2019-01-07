#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(const char &a, const char &b){
    return a > b;
}
int main(){
    // freopen("data.in", "r", stdin);
    int res;
    string s, a, b;
    cin >> s;
    s.insert(0, 4-s.length(), '0');
    do{
        a = s; b =s;
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end());
        res = stoi(a) - stoi(b);
        s = to_string(res);
        s.insert(0, 4-s.length(), '0');
        cout << a << " - " << b << " = " << s << endl;
    }while(s != "6174" && s != "0000");
    return 0;
}
