#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    long long p;
    int N, i;
    scanf("%d %lld", &N, &p);
    int array[N];
    for(i = 0; i < N; ++i)
        scanf("%d", &array[i]);
    sort(array, array+N);
    int ans = 0, tmp;
    for(i = 0; i < N; ++i){
        for(int j = i+ans; j < N; ++j)
            if(array[j] <= array[i]*p){
                tmp = j - i + 1;
                if(tmp > ans)
                    ans = tmp;
            }
            else break;
    }
    printf("%d\n", ans);
    return 0;
}