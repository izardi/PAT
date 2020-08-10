#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    unordered_map<int, int> mp;
    int N;
    int a,b;
    scanf("%d", &N);
    for(int i = 1; i<= N; ++i){
        scanf("%d %d", &a, &b);
        mp[a] = b;
        mp[b] = a;
        mp[a*100000+b] = mp[b*100000 + a] = i;
    }
    scanf("%d", &N);
    int arr[10001];
    unordered_map<int, int> mpp;
    for(int i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
        mpp[arr[i]] = 1;
    }
    vector<int> res;
    for(int i = 0; i < N; ++i){
        if(mp[arr[i]*1000000 + p[arr[i]]*100000 + ])
    }
    return 0;
}
