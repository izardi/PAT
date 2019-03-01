#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int N, sum, cnt = 0;
    scanf("%d", &N);
    char tmp[6];
    int hash[10009] = {0};
    int list[10009];
    for(int i = 0; i < N; ++i){
        scanf("%s", tmp);
        sum = 0;
        for(int i = 0; i < strlen(tmp); ++i)
            sum += tmp[i] - '0';
        if(hash[sum] == 0){
            hash[sum] = 1;
            list[cnt++] = sum;
        }
    }
    sort(list, list+cnt);
    printf("%d\n%d", cnt, list[0]);
    for(int i = 1; i < cnt; ++i)
        printf(" %d", list[i]);
    return 0;
}
