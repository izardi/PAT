#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, M, tmp;
    int arr[10000] = {0};
    scanf("%d %d", &N, &M);
    while(M--){
        scanf("%d", &tmp);
        arr[tmp] = 1;
    }
    int cnts = 0, cntw = 0;
    char id[5];
    while(N--){
        scanf("\n%s %d", id, &tmp);
        int flag = 0;
        while(tmp--){
            scanf("%d", &M);
            if(arr[M]){
                if(!flag){
                    printf("%s: %04d", id, M);
                    flag = 1;
                    ++cntw; ++cnts;
                }
                else { ++ cntw; printf(" %04d", M);}
            }
        }
        if(flag) printf("\n");
    }
    printf("%d %d", cnts ,cntw);
    return 0;
}
