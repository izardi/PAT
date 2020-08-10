#include <cstdio>
#include <cstring>
int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d\n", &N);
    int arr[1000] = {0};
    char tmp[6];
    int cnt = 0;
    while(N--){
        int res = 0;
        scanf("%s", tmp);
        getchar();
        for(int i = 0; i < strlen(tmp); ++i)
            res += (tmp[i] - '0');
        if(arr[res] == 0){ ++cnt; arr[res] = 1;}
        else if(arr[res] == 1){
            arr[res] = - 1;
        }
    }
    printf("%d\n", cnt);
    int flag = 0;
    for(int i = 0; i < 1000; ++i)
        if(arr[i] != 0){
            if(flag) printf(" ");
            printf("%d", i);
            flag = 1;
        }
    return 0;
}
