#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);    
    int N;
    scanf("%d", &N);
    int a[100005] = {0}, b[100005] = {0};
    for(int i = 0; i < N; ++i){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b+N);
    int max = 0, cnt = 0;
    int res[100005] = {0};
    for(int i = 0; i < N; ++i){
        if(a[i] == b[i] && max < b[i])
            res[cnt++] = b[i];
        if(max < a[i])
            max = a[i];
    }
    printf("%d\n", cnt); 
    for(int i = 0; i < cnt; ++i){
        if(i != 0) printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}
