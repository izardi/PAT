#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int NC;
    int NP;
    int coupons[100001];
    int product[100001];

    int i, j;
    scanf("%d", &NC);
    for(i = 0; i < NC; i++)
        scanf("%d", &coupons[i]);
    scanf("%d", &NP);
    for(i = 0; i < NP; i++)
        scanf("%d", &product[i]);

    sort(coupons, coupons+NC);
    sort(product, product+NP);

    long long result = 0;

    j = NC - 1;
    for( i = NP-1; i >= 0; i--){
        if(product[i] < 0)
            break;
        if(j < 0 || coupons[j] < 0)
            result += product[i];
        else
            result += product[i]*coupons[j--];
    }
    int k, l = 0;
    for(k = 0; k <= i; k++){
        if( l >= j || coupons[l] > 0)
            result += 0;
        else
            result += product[k]*coupons[l++];
    }

    printf("%lld", result);
    return 0;
}
