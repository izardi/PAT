#include <cstdio>

struct Node{
    int D, N;
} L[100005];

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int F, N, K;
    scanf("%d %d %d\n", &F, &N, &K);
    int tmp; 
    while(N--){
        scanf("%d", &tmp);
        scanf("%d %d", &L[tmp].D, &L[tmp].N);
    }
    int cnt = 0;
    int flag = 1;
    int NH = -1, tmpH = -1, LH = F, rear = -1;
    int lr = F;
    int nH = F;
    if(K != 1){
    while(F != -1){
        ++cnt;
        F = L[F].N;
        if(cnt % K == 0){
            tmpH = L[LH].N;
            rear = LH;
            do{
                NH = tmpH;
                tmpH = L[tmpH].N;
                L[NH].N = rear;
                rear = NH;
            }while(tmpH != F);
            if(flag){
                flag = 0;
                nH = NH;
            }
            else{
                L[lr].N = NH;
                lr = LH;
            }
            LH = F;
        }
    }
    L[lr].N = LH;
    }
    while(L[nH].N != -1){
        printf("%05d %d %05d\n", nH, L[nH].D, L[nH].N);
        nH = L[nH].N;
    }
    printf("%05d %d -1\n", nH, L[nH].D);
    return 0;
}
