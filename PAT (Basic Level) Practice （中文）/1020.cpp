#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
    double reg, sum, price;
}No[1001];

bool cmp(struct Node a, struct Node b){
    return a.price > b.price;
}

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, D;
    scanf("%d %d", &N, &D);
    double reg[N], price[N];

    for(int i = 0; i < N; ++i)
        scanf("%lf", &No[i].reg);
    for(int i = 0; i < N; ++i){
        scanf("%lf", &No[i].sum); 
        No[i].price = No[i].sum/No[i].reg; 
    }
    sort(No, No+N, cmp);
    double res = 0;
    double need = 0;
    int i = 0;
    for(; i < N; ++i){
        if(need+ No[i].reg < D){
            need += No[i].reg;
            res += No[i].sum;
        }
        else break;
    }
    if(i != N)
        res += (D - need) * No[i].price;
    printf("%.2lf", res);
    return 0;
}
