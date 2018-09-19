#include <cstdio>

struct Node{
    int G, S, K;
};

int main(){
    struct Node tmp, N1, N2;

    scanf("%d.%d.%d", &tmp.G, &tmp.S, &tmp.K);
    N1 = tmp;
    scanf("%d.%d.%d", &tmp.G, &tmp.S, &tmp.K);
    N2 = tmp;

    const int Sickle = 17;
    const int Knut = 29;
    tmp.G = tmp.S = tmp.K = 0;
    if(N1.K + N2.K >= Knut){
        tmp.K = (N1.K + N2.K - Knut);
        N1.S++;
    }else
        tmp.K = (N1.K + N2.K);
    if(N1.S + N2.S >= Sickle){
        tmp.S = (N1.S + N2.S - Sickle);
        N1.G++;
    }else
        tmp.S = (N1.S + N2.S);
    tmp.G = (N1.G + N2.G);
    printf("%d.%d.%d", tmp.G, tmp.S, tmp.K);
    return 0;
}
