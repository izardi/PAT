#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp (char c1, char c2){
    return c1 >= c2;
}

int main(int argc, char *argv[])
{
    //freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    char mas[5];
    char mis[5];
    do{
        sprintf(mas, "%04d", N);
        sprintf(mis, "%04d", N);
        sort(mas, mas + 4, cmp);
        sort(mis, mis + 4);
        int n1 = atoi(mas);
        int n2 = atoi(mis);
        N = n1 - n2;
        printf("%04d - %04d = %04d\n", n1, n2, N );
    } while(N != 0 && N != 6174);
    return 0;
}
