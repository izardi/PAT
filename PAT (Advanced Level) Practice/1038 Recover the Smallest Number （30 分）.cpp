#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
bool cmp (const string& a, const string& b){return a + b < b + a;}
int main(){
    int N, i;
    scanf("%d", &N);
    string num[10001];
    for( i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N, cmp);
    string result;
    for( i = 0; i < N; i++)
        result += num[i];
    for(i = 0; i < result.size() && result[i] == '0'; i++);
    if( i == result.size())
        printf("0");
    else
        printf("%s", result.c_str()+i);
    return 0;
}
