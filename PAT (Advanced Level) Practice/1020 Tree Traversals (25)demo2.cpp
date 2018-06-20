#include <cstdio>
int postorder[30];
int inorder[30];
int levelorder[30][16];//N最大为30 最后一层最多有16个结点
int cnt[30] = {0};
void solve(int depth, int postL, int inL, int len){
    if(len == 0) 
        return;
    int root = postorder[postL + len - 1];
    levelorder[depth][cnt[depth]++] = root;
    int i;
    for(i = inL; i < inL+len; i++)
        if( inorder[i] == root)
            break;
    int llen = i - inL;
    int rlen = inL + len - i - 1;
    solve(depth+1, postL, inL,llen);
    solve(depth+1, postL+llen, inL+llen+1, rlen);
}

int main(){
    int N;
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 16; j++)
            levelorder[i][j] = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);
        
    solve(0, 0, 0, N);
    int flag = 1;
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 16; j++){
            if(levelorder[i][j] != 0){
                if(flag){ printf("%d", levelorder[i][j]); flag = 0; }
                else printf(" %d", levelorder[i][j]);
            }
        }
    }
    return 0;
}
