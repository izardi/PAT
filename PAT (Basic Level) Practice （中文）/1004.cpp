#include <cstdio>
#include <cstring>
int main(){
    freopen("in", "r", stdin);
    int N;
    char HN[11], HI[11], LN[11], LI[11], TN[11], TI[11];
    int H = 0, L = 100, T  =0;
    scanf("%d", &N);

    while(N--){
        scanf("\n%s %s %d", TN, TI, &T);
        if(T > H) {
            H = T;
            strcpy(HN, TN);
            strcpy(HI, TI);
        }
        if(T < L){
            L = T;
            strcpy(LN, TN);
            strcpy(LI, TI);
        }
    }
    printf("%s %s\n%s %s", HN, HI, LN, LI);
    return 0;
}