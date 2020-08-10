#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int arr[10001] = {0};
    int tmp;
    for(int i = 1; i <= N; ++i){
        scanf("%d", &tmp);
        tmp -= i;
        if(tmp < 0)  tmp *= -1;
        ++arr[tmp];
    }
    for(int i = N-1; i >= 0; --i)
        if(arr[i] > 1){
            printf("%d %d\n", i, arr[i]);
        }
    return 0;
}
