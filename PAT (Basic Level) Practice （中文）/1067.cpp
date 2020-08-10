#include <cstdio>
#include <cstring>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    char passwd[22], tmp[1000];
    int N;
    scanf("%s %d", passwd, &N);
    int flag = 1;
    int cnt = 0;
    while(1){
        scanf("\n%s", tmp);
        if(strcmp(tmp, "#") == 0) break;
        ++cnt;
        if(cnt > N) break;
        if(strcmp(passwd, tmp) == 0){
            printf("Welcome in\n");    
            flag = 0;
            break;
        }
        else printf("Wrong password: %s\n", tmp);
    }
    if(flag && cnt == N+1) printf("Account locked\n");
    return 0;
}
