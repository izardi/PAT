#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    int arr[10001];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    sort(arr, arr+N, cmp);
    int m, n;
    m = n = (int)sqrt(N);
    while(m * n != N){
        if(m*n < N)
            ++m;
        if(m * n > N)
            --n;
    }
    int res[m][n];

    int l = 0;
    int cnt = 0;
    while(cnt < N){
        for(int i = l; i < n-l-1 && cnt < N; ++i)
            res[l][i] = arr[cnt++];
        for(int i = l; i < m-l-1 && cnt < N; ++i)
            res[i][n-l-1] = arr[cnt++];
        for(int i = n-l-1; i > l && cnt < N; --i)
            res[m-l-1][i] = arr[cnt++];
        for(int i = m-l-1; i > l && cnt < N; --i)
            res[i][l] = arr[cnt++];
        ++l;
    }
    for(int i = 0; i < m; ++i){
        for(int j= 0; j < n; ++j){
            if(j != 0) printf(" ");
            printf("%d", res[i][j]);
        }
       printf("\n");
    }
    return 0;
}
