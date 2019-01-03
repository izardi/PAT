#include <cstdio>

struct Node{
    int data, lchild, rchild;
} tree[50005];
int preOrder[50005];
int inOrder[50005];
int cnt = 0, flag = 1;

int Solve(int preL, int inL, int len){
    if(len <= 0) return -1;
    int root = preOrder[preL];
    tree[cnt].data = root;
    int tmp = cnt++;
    int L = 0;
    for(int i = inL; i < inL + len && root != inOrder[i]; ++i)
        ++L;
    int R = len - 1 - L;
    tree[tmp].lchild = Solve(preL + 1, inL, L);
    tree[tmp].rchild = Solve(preL + 1 + L, inL+1+L, R);
    return tmp;
}

void posOrderTraversal(int root){
    if(root != -1){
        posOrderTraversal(tree[root].lchild);
        posOrderTraversal(tree[root].rchild);
        if(flag){
            printf("%d", tree[root].data);
            flag = 0;
        }
        return;
    }
}
int main(){
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
        scanf("%d", &preOrder[i]);
    for(i = 0; i < N; ++i)
        scanf("%d", &inOrder[i]);

    Solve(0, 0, N);
    posOrderTraversal(0);
    return 0;
}