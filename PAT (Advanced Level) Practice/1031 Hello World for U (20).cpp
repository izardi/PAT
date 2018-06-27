#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.size();
    
    int n1, n2;
    for(n1 = 0; n1 < len; n1++){
        n2 = len+2 - 2*n1;
        if(n2 < n1) break;
    }
    if(n2 < n1)
        n1--;
    n2 = len+2 - 2*n1;
    string temp;
    for(int i = 0; i < n2 - 2; i++)
        temp += " ";
    for(int i= 0; i < n1-1; i++)
        cout << s[i] << temp << s[len-1-i] << endl;
    for(int i = n1-1; i < n2 + n1-1; i++)
        cout << s[i];
    cout << endl;
    return 0;
}