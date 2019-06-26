#include <cstdio>

int max(int a, int b){
    return a > b ? a : b;
}

struct Node{
    int data;
    struct Node *lc, *rc;
};

int getHeight(Node *root){
    if(root == NULL) return 0;
    return max(getHeight(root->lc), getHeight(root->rc))+1;
}

Node *rotateLeft(Node *root){
    Node *t = root->rc;
    root->rc = t->lc;
    t->lc = root;
    return t;
}

Node *rotateRight(Node *root){
    Node *t = root->lc;
    root->lc = t->rc;
    t->rc = root;
    return t;
}

Node *rotateLeftRight(Node *root){
    root->lc = rotateLeft(root->lc);
    return rotateRight(root);
}

Node *rotateRightLeft(Node *root){
    root->rc = rotateRight(root->rc);
    return rotateLeft(root);
}

Node *insert(Node *root, int data){
    if(root == NULL){
        root = new Node;
        root->data = data;
        root->lc = root->rc = NULL;
    }
    else if(data < root->data){
        root->lc = insert(root->lc, data);
        if(getHeight(root->lc) - getHeight(root->rc) == 2)
            root = data < root->lc->data ? rotateRight(root) : rotateLeftRight(root);
    }
    else {
        root->rc = insert(root->rc, data);
        if(getHeight(root->rc) - getHeight(root->lc) == 2)
            root = data > root->rc->data ? rotateLeft(root) : rotateRightLeft(root);
    }
    return root;
}
int main(){
    //freopen("d.txt", "r", stdin);
    int N, tmp;
    scanf("%d", &N);
    struct Node *root = NULL;
    while(N--){
        scanf("%d", &tmp);
        root = insert(root, tmp);
    }
    printf("%d", root->data);
    return 0;
}