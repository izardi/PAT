#include <cstdio>
#include <cmath>
using namespace std;

int max(const int a, const int b){
    return a > b ? a : b;
}

struct Node{
    int data;
    struct Node *lc, *rc;
};

Node *insert(struct Node *root, int data){
    if(root == NULL){
        root = new Node();
        root->data = data;
        root->lc = root->rc = NULL;
    }
    else if(abs(data) < abs(root->data))
        root->lc = insert(root->lc, data);
    else
        root->rc = insert(root->rc, data);
    return root;
}

bool judge1(Node *root){// 判断红点的lc rc是否为黑点
    if(root == NULL) return true; //从上往下递归一旦出现红点左右子树的颜色不为黑跳出返回错位
    if(root->data < 0){
        if(root->lc != NULL && root->lc->data < 0) return false;
        if(root->rc != NULL && root->rc->data < 0) return false;
    }
    return (judge1(root->lc) && judge1(root->rc));
}

int getNum(Node *root){// 左右子树黑点的数量
    if(root == NULL) return 0; int l = getNum(root->lc);
    int r = getNum(root->rc);
    return root->data > 0 ? max(l, r)+1 : max(l, r);
}

bool judge2(Node *root){// 判断左右黑点的数量是否相等从根结点递归向左右如果不相等直接 return 
    if(root == NULL) return true;
    if(getNum(root->lc) != getNum(root->rc)) return false;
    return (judge2(root->lc) && judge2(root->rc));
}

int main(){
    //freopen("d.txt", "r", stdin);
    int K, N;//K total number of cases, N number of nodes
    scanf("%d", &K);
    while(K--){
        struct Node *root = NULL;
        int arr[35]; 
        scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            scanf("%d", &arr[i]);//顺序为先序遍历不用再去做旋转操作插入几位正确的顺序
            root = insert(root, arr[i]);//负数代表红点
        }
        if(arr[0] < 0 || !judge1(root) || !judge2(root))
            printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}