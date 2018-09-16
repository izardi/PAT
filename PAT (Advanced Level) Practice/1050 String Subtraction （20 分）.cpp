#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
    char s1[10001], s2[10001];
    cin.getline(s1, 10001);
    cin.getline(s2, 10001);
    int hash[128] = {0};
    for(int i = 0; i < strlen(s2); i++)
        hash[s2[i] - '\0'] = 1;

    for(int i = 0; i < strlen(s1); i++)
        if(!hash[s1[i] - '\0'])
            printf("%c",s1[i]);

    return 0;
}
