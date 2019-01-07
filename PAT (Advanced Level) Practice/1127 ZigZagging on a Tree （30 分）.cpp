#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

struct Node{
    int l, r, data;
}tree[31];
int N, inorder[31], postorder[31], cnt = 0;

int Solve(int inL, int postL, int len){
    if(len <= 0) return - 1;
    int root = postorder[postL + len - 1];
    tree[cnt].data = root;
    int cur = cnt++;

    int i, llen = 0, rlen = 0;
    for(i = inL; i < inL + len && inorder[i] != root; ++llen, ++i);
    rlen = len - 1 - llen;

    tree[cur].l = Solve(inL, postL, llen);
    tree[cur].r = Solve(inL + llen + 1, postL + llen, rlen);
    return cur;
}

int main(){
    freopen("data.in", "r", stdin);
    scanf("%d", &N);

    for(int i = 0; i < N; ++i)
        tree[i].l = tree[i].r = -1;
    for(int i = 0; i < N; ++i)
        scanf("%d", &inorder[i]);
    for(int i = 0; i < N; ++i)
        scanf("%d", &postorder[i]);
    Solve(0, 0, N);

    queue<int> Q;
    stack<int> S, TPS;
    S.push(0);
    int flag = 0;
    while(!Q.empty() || !S.empty()){
        int tmp;
        while(!S.empty()){
            tmp = S.top();
            S.pop();
            TPS.push(tmp);
            if(flag) printf(" ");
            printf("%d", tree[tmp].data);
            flag = 1;
        }
        while(!TPS.empty()){
            tmp = TPS.top();
            TPS.pop();
            if(tree[tmp].l != -1)
                Q.push(tree[tmp].l);
            if(tree[tmp].r != -1)
                Q.push(tree[tmp].r);
        }
        while(!Q.empty()){
            tmp = Q.front();
            Q.pop();
            if(flag) printf(" ");
            printf("%d", tree[tmp].data);
            if(tree[tmp].l != -1)
                S.push(tree[tmp].l);
            if(tree[tmp].r != -1)
                S.push(tree[tmp].r);
        }
    }
    return 0;
}