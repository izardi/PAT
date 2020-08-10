#include <cstdio>

int main(){
    freopen("in", "r", stdin);
    long T, A, B, C;
    scanf("%ld", &T);
    for(int i = 1; i <= T; ++i){
        scanf("%ld %ld %ld", &A, &B, &C);
        printf("Case #%d: ",i);
        printf("%s\n", A + B > C ? "true" : "false");
    }
    return 0;    
}
