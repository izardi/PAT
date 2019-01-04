#include <cstdio>
int M, N;
int level[1005];
int notflag = 0;
int maxflag = 0;
int fixflag = 0;

void postOrderTraversal(int idx){
    if(idx > N) return;
    postOrderTraversal(2*idx);
    postOrderTraversal(idx*2+1);
    if(notflag) printf(" ");
    printf("%d", level[idx]);
    notflag = 1;
}

void levelOrderTraversal(int idx){
    if(idx > N) return;
    if(idx != 1){
        if(level[idx/2] > level[idx]){
            if(!fixflag){
                fixflag = 1;
                maxflag = 1;
            }
            else if(maxflag == 0){
                    notflag = 1;
                    return;
                }
        }
        else{
            if(!fixflag){
                fixflag = 1;
            }
            else if(maxflag == 1){
                notflag =1;
                return;
            }
        }
    }
    levelOrderTraversal(idx*2);
    levelOrderTraversal(idx*2+1);
}

int main(){
    scanf("%d %d", &M, &N);
    for(int i = 0; i < M; ++i){
        for(int j = 1; j <= N; ++j)
            scanf("%d", &level[j]);
        fixflag = 0; notflag = 0; maxflag = 0;
        levelOrderTraversal(1);
        if(notflag)
            printf("Not Heap\n");
        else if(maxflag)
            printf("Max Heap\n");
        else
            printf("Min Heap\n");
        notflag = 0;
        postOrderTraversal(1);
        printf("\n");
    }
    return 0;
}