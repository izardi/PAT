#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char CH[] = {"0123456789JQK"};

int main(){
    //freopen("d.in", "r", stdin);
    string A, B;
    cin >> A >> B;
    int tmp;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    if(A.length() > B.length())
        B.append(A.length() - B.length(), '0');
    else A.append(B.length() - A.length(), '0');

    for(int i = 0; i < B.length(); ++i){
        if(i % 2 == 0){
            tmp = B[i]-'0' + A[i]-'0';
            B[i] = CH[(tmp%13)];
        }   
        else{
            tmp = B[i] - A[i];
            if(tmp < 0) tmp += 10;
            B[i] = CH[tmp];
        }
    }   
    for(int i = B.size()-1; i >= 0; --i)
        cout << B[i];
    return 0;
}