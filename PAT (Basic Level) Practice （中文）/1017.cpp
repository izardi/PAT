#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int s[1001], d;
    char c;
    int j = 0;
    while(scanf("%c", &c) != EOF){
        if(c == ' ') break;
        s[j++] = int(c - '0');
    } 
    scanf("%d", &d);
    int res[1001];
    int reg = 0;
    int k = 0;
    for(int i = 0; i < j; ++i){
        reg = reg*10+s[i];
        res[k++] = reg / d;
        reg %= d;
    }
    int flag = 1;
    for(int i = 0; i < k; ++i){
        if(flag && res[i] == 0){
            continue;
        }
        flag = 0;
        printf("%d", res[i]);
    }
    if(flag) printf("0");
    printf(" %d", reg);
    return 0;
}
