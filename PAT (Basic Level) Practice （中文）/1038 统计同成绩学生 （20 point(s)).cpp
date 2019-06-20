#include <cstdio>

int main(){
    // freopen("d.in", "r", stdin);
    int N;
    scanf("%d", &N);
    int hash[101] = {0};
    int tmp;
    while(N--){ 
        scanf("%d", &tmp);
        ++hash[tmp];
    }
    scanf("%d", &N);
    int flag = 0;
    while(N--){
        scanf("%d", &tmp);
        if(flag) printf(" ");
        flag = 1;
        printf("%d", hash[tmp]);
    }
    return 0;
}