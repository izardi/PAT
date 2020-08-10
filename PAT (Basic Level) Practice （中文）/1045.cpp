#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int arr[100005];
    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);

    int l[100005] = {0}, m[100005] = {0};
    int prel= arr[0]; int prem= arr[N-1];
    for(int i = 0; i < N; ++i){
        if(arr[i] > prel)
            prel = arr[i];
        l[i] = prel;  
        if(arr[N-i-1] < prem)
            prem = arr[N-i-1];
        m[N-i-1] = prem;
    }
    int res[100005] = {0};
    int cnt = 0;
    prel = -1000000000;
    for(int i = 0; i < N; ++i){
        if(arr[i] >= l[i] && arr[i] <= m[i])
            if(arr[i] != prel){
                prel = arr[i];
                res[cnt++] = prel;
            }
    }
    sort(res, res+cnt);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; ++i){
        if(i != 0) printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}
