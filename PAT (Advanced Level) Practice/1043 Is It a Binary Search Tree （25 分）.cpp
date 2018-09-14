#include <cstdio>
#include <cstdlib>

typedef struct Node{
    struct Node *left, *right;
    int data;
}BST;

static int order[1001], preorder[1001], posorder[1001];
static int count = 0;

void insert(BST *&root, int data){
    if(root == nullptr){
        root = (BST*)malloc(sizeof(BST));
        root->data = data;
        root->left = root->right =nullptr;
    }
    else{
        if(root->data > data)
            insert(root->left, data);
        else
            insert(root->right, data);
    }
}

void preOrderTraversal(BST* root){
    if(root == nullptr)
        return;
    preorder[count++] = root->data;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void posOrderTraversal(BST* root){
    if(root == nullptr)
        return;
    posOrderTraversal(root->left);
    posOrderTraversal(root->right);
    posorder[count++] = root->data;
}

void mirrorBSTpreOrderTraversal(BST* root){
    if(root == nullptr)
        return;
    preorder[count++] = root->data;
    mirrorBSTpreOrderTraversal(root->right);
    mirrorBSTpreOrderTraversal(root->left);
}

void mirrorBSTposOrderTraversal(BST* root){
    if(root == nullptr)
        return;
    mirrorBSTposOrderTraversal(root->right);
    mirrorBSTposOrderTraversal(root->left);
    posorder[count++] = root->data;
}

int main(){
    int N, i;
    BST * root = nullptr;

    scanf("%d", &N);
    for(int i = 0; i < N; i++ ){
        scanf("%d", &order[i]);
        insert(root, order[i]);
    }
    count = 0;
    preOrderTraversal(root);

    for(i = 0; i < N; i++)
        if(order[i] != preorder[i])
            break;

    if(i != N ){
        count = 0;
        mirrorBSTpreOrderTraversal(root);
        for(i = 0; i < N; i++)
            if(order[i] != preorder[i])
                break;
        if(i != N){
            printf("NO\n");
            return 0;
        }
        else{
            count = 0;
            mirrorBSTposOrderTraversal(root);
        }
    }else{
        count = 0;
        posOrderTraversal(root);
    }

    printf("YES\n");
    printf("%d", posorder[0]);
    for(i = 1; i < N; i++)
        printf(" %d", posorder[i]);
    return 0;
}
