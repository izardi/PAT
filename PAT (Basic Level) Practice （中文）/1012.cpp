#include <cstdio>

int main(){
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    double A4 = 0;
    int flag = 0;
    int count = 0, tmp;
    while(N--){
        scanf("%d", &tmp);
        switch( tmp % 5 ){
            case 0:
                if(tmp % 2 == 0) A1 += tmp;
                break;
            case 1:
                if(flag == 2){
                    flag = 1;
                    A2 -= tmp;
                }
                else{
                    flag = 2;
                    A2 += tmp;
                }
                break;
            case 2:
                ++A3;
                break;
            case 3:
                ++count;
                A4 += tmp;
                break;
            case 4:
                if(A5 < tmp) A5 = tmp;
                break;
            default: break;
        }
    }
    if(A1) printf("%d", A1);
    else printf("N");
    if(flag) printf(" %d", A2);
    else printf(" N");
    if(A3) printf(" %d", A3);
    else printf(" N");
    if(count) printf(" %0.1f", A4/count);
    else printf(" N");
    if(A5) printf(" %d", A5);
    else printf(" N");
    return 0;
}
