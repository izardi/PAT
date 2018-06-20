#include <cstdio>
#include <cstring>

int main(){
    char original[21];
    int hash1[10] = {0};
    int hash2[10] = {0};
    scanf("%s", original);
    int len = strlen(original);
    int doublen[21];
    int cnt = 0;
    int carrying = 0; //进位carrying
    int tmp;
    for(int i = len-1; i >= 0; i--) {
        tmp = original[i] - '0';
        hash1[tmp]++;
        doublen[cnt++] = tmp*2%10 + carrying;
        hash2[doublen[cnt-1]]++;
        carrying = tmp*2/10;
    }
    if(carrying) {
        doublen[cnt++] = carrying;
        hash2[doublen[cnt-1]]++;
    }
    int i;
    for(i = 0; i < 10; i++)
        if(hash1[i] != hash2[i]) {
            printf("No\n");
            break;
        }
    if(i == 10)
        printf("Yes\n");
    for(i = cnt - 1; i >= 0; i--)
        printf("%d", doublen[i]);
    return 0;
}