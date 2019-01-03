#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int nextPrime(int n){
    int i;
    for(i = n; ; ++i){
        int j;
        for(j = 2; j <= sqrt(n); j++){
            if( i % j == 0)
                break;
        }
        if(j == int(sqrt(n)+1)) break;
    }
    return i;
}
int main(){
    int MSIZE , N, M, tmp;
    scanf("%d %d %d", &MSIZE, &N, &M);
    MSIZE = nextPrime(MSIZE);
    vector<int> Tb(MSIZE);
    for(int i = 0; i < N; ++i){
        int flag = 0;
        scanf("%d", &tmp);
        for(int j = 0; j < MSIZE; ++j){
            int pos = (tmp + j*j) % MSIZE;
            if(Tb[pos] == 0){
                Tb[pos] = tmp;
                flag = 1;
                break;
            }
        }
        if(!flag) printf("%d cannot be inserted.\n", tmp);
    }
    int ans = 0;
    for(int i = 0; i < M; ++i){
        scanf("%d", &tmp);
        for(int j = 0; j <= MSIZE; ++j){
            ans++;
            int pos = (tmp + j*j) % MSIZE;
            if(Tb[pos] == tmp || Tb[pos] == 0) break;
        }
    }
    printf("%.1lf\n", ans*1.0/M);
    return 0;
}