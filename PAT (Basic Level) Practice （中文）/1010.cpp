#include <cstdio>

int main(){
    freopen("in", "r", stdin);
    int p, e;
    int flag = 0;
    while(scanf("%d %d", &p, &e) != EOF){
        if(e != 0 && p != 0){
            if(flag) printf(" ");
            printf("%d %d", p*e, e-1);
            flag = 1;
        }
    }
    if(!flag) printf("0 0\n");
    return 0;
}
