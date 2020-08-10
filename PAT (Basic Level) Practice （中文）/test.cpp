#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return(*(int *)a-*(int *)b);
}
int main(){
    freopen("in", "r", stdin);
    int N;
    long long p;
    int max_length = 0;
    int array [100001];

    scanf("%d %lld", &N, &p);
    for (int i = 0; i < N; i++)
        scanf("%d", &array[i]);
    qsort(array,N,sizeof(array[0]),cmp);

    int M, m;
    for(m = 0; m < N && max_length < N-m; m++){
        for(M = m+max_length; M < N; M++)
            if(array[M] > array[m]*p)
                break;
        if (M - m > max_length)
            max_length = M - m;
    }
    printf("%d", max_length);
    return 0;
}
