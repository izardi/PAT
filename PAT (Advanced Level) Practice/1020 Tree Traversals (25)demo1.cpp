#include <cstdio>
int postorder[30];
int inorder[30];
int levelorder[100000] = {0};

void solve(int postL, int inL, int levelL, int len){
    if(len == 0)
        return;
    int root = postorder[postL + len - 1];
    levelorder[levelL] = root;
    int i;
    for(i = inL; i < inL+len; i++)
        if( inorder[i] == root)
            break;
    int llen = i - inL;
    int rlen = inL + len - i - 1;
    solve(postL, inL, levelL*2, llen);
    solve(postL+llen, inL+llen+1, levelL*2+1, rlen);
}

int main(){
    int N;
    int levelL = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);
    solve(0, 0, levelL, N);
    for(int i = 1; i < 100000; i++)
        if(levelorder[i] != 0) {
            if (i == 1) printf("%d", levelorder[i]);
            else printf(" %d", levelorder[i]);
        }
    return 0;
}