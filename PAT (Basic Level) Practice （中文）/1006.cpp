#include <cstdio>

int main(){
    freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    int B = n/100;
    int S = (n%100)/10;
    int G = (n%100)%10;
    while(B--) printf("B");
    while(S--) printf("S");
    for(int i = 1; i <= G; ++i) printf("%d", i);
    return 0;
}
