#include <cstdio>
#include <vector>
using namespace std;
int preOrder[31], posOrder[31], inOrder[31];
int cnt = 0;
int flag = 1;
struct Node{
    int data, lc, rc;
    Node(){
        lc = rc = -1;
    }
}Tree[35];

void DFS(int preL, int preR, int posL, int posR){
    if(preL>=preR) return;
    int fa=preL;
    int postIdx;
    for(int i=posL;i<posR;i++)
        if(preOrder[preL+1] == posOrder[i]){
            postIdx=i; //val在后序遍历中的索引
            break;
        }
    int num=postIdx-posL;
    if(preR-preL-1==num) flag=0;

    Tree[fa].lc=preL+1;
    DFS(preL+1,preL+num+1,posL,postIdx);
    if(preR-preL-1>num){
        Tree[fa].rc=preL+num+2;
        DFS(preL+num+2,preR,postIdx+1,posR-1);
    }
}

void inOrderTraversal(int idx){
    if(idx != -1){
        inOrderTraversal(Tree[idx].lc);
        if(flag) printf(" ");
        printf("%d", preOrder[idx]);
        flag = 1;
        inOrderTraversal(Tree[idx].rc);
    }
    return;
}

int main(){
    freopen("d.txt", "r", stdin);
    int N; // N <= 30 number of nodes;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) scanf("%d", &preOrder[i]);     //  根左右
    for(int i = 1; i <= N; ++i) scanf("%d", &posOrder[i]);//逆序变为根右左
    DFS(1, N, 1, N);
    if(flag) printf("Yes\n");
    else printf("No\n");
    flag = 0;
    inOrderTraversal(1);
    printf("\n");
    return 0;
}