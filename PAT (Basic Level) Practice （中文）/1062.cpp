#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N1, M1, N2, M2, M;
    scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &M);
    if(N1*M2 > N2*M1){
        swap(N1, N2);
        swap(M1, M2);
    }
    
    int flag = 0;
    int i = 1;
    while(i * M1 <= N1*M) ++i;
    while(i * M1 > N1 * M && i * M2 < N2*M){
        if(gcd(i, M) == 1){
            if(flag) printf(" ");
            printf("%d/%d", i, M);
            flag = 1;
        }
        ++i;
    }
    return 0;
}
