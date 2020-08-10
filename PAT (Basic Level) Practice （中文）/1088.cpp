#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int M, X, Y;
    double arr[3] = {0};
    scanf("%d %d %d", &M, &X, &Y);
    int flag = 0;
    for(int i = 9; i >= 1; --i){
        for(int j = 9; j >= 0; --j){
            arr[0] = i*10 + j;
            arr[1] = j*10 + i;
            if(arr[1]*X == abs(arr[0]-arr[1])*Y){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    arr[2] = arr[1]/Y;
    if(flag){
        printf("%d", (int)arr[0]);
        for(int i = 0; i < 3; ++i){
            if(M > arr[i]) printf(" Gai");
            else if(M == arr[i]) printf(" Ping");
            else printf(" Cong");
        }
    }
    else printf("No Solution");
    return 0;
}
