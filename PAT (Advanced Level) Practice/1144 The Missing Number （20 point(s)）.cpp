#include <cstdio>
#include <map>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    map<int, int> mp;
    int cnt = 0;
    int tmp;
    for(int i = 0; i < N; ++i){
        scanf("%d", &tmp);
        mp[tmp] = 1;
    }
    for(int i = 1; i < 100005; ++i){
        if(mp[i] == 0){
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}
