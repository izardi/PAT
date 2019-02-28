#include <cstdio>
#include <stack>
using namespace std;

int N, inOrder[32] = {0}, preOrder[32] = {0};
struct Node{
    int left, right;
    Node(){
        left = right = 0;
    }
} Tree[33];

int Solve(int preL, int inL, int len){
    if(len == 0)
        return 0;
    if(len == 1)
        return preOrder[preL];

    int root = preOrder[preL];
    int i;
    for(i = inL; i < inL + len; ++i)
        if( root == inOrder[i])
            break;
    int llen = i - inL;
    Tree[root].left = Solve(preL+1, inL, llen);
    Tree[root].right = Solve(preL+llen+1, inL+llen+1, len-llen-1);
    return root;
}

int flag = 1;
void postOrderTraversal(int root){
    if(root != 0){
        postOrderTraversal(Tree[root].left);
        postOrderTraversal(Tree[root].right);
        if(flag){
            printf("%d", root);
            flag = 0;
        }
        else printf(" %d", root);
    }
}
int main(){
    int cnt = 1;
    char tmp[5];
    stack<int> S;
    scanf("%d", &N);

    for(int i = 1; i <= N; ){
        scanf("%s", tmp);
        if(tmp[1] == 'u'){
            scanf("%d", &preOrder[cnt]);
            S.push(preOrder[cnt]);
            cnt++;
        }
        else{
            inOrder[i] = S.top();
            S.pop();
            ++i;
        }
    }

    int root = preOrder[1];
    postOrderTraversal(Solve(1,1,N));

    return 0;
}
