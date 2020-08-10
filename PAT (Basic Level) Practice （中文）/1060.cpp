#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}
int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int arr[100005];
    int i;
    for(i = 1; i <= N; ++i)
        scanf("%d", &arr[i]);
    sort(arr+1, arr+N+1, cmp); 

    i = 1; 
    while(i <= N && arr[i] > i)
        ++i;
    printf("%d", i-1);
    return 0;
}
