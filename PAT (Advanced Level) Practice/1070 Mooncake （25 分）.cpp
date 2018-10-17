#include <cstdio>
#include <algorithm>
using namespace std;

struct Mooncake{
    float price;
    float weight;
    float unit;
}Moo[1010];

int cmp(const struct Mooncake &a, const struct Mooncake &b){
    return (a.unit > b.unit);
}

int main(){
    int N, D, i;
    scanf("%d %d", &N, &D);

    for(i = 0; i < N; ++i){
        scanf("%f", &Moo[i].weight);
    }
    for(i = 0; i < N; ++i){
        scanf("%f", &Moo[i].price);
        Moo[i].unit = Moo[i].price/Moo[i].weight;
    }

    sort(Moo, Moo+N, cmp);
    float ans = 0.0;
    for(i = 0; i < N; ++i){   
        if(D >= Moo[i].weight){
            ans += Moo[i].price;
            D -= Moo[i].weight;
        }else{
            ans += D*Moo[i].unit;
            break;
        }
    }
    printf("%.2f", ans);
    return 0;
}