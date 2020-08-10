#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int hash[128] = {0};

    for(int i = 0; i < a.length(); ++i){
        if(!hash[a[i]])
            printf("%c", a[i]);
        hash[a[i]] = 1;
    }

    for(int i = 0; i < b.length(); ++i){
        if(!hash[b[i]])
            printf("%c", b[i]);
        hash[b[i]] = 1;
    }
    return 0;
}
