#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node{
	int data;
	struct Node *lchild, *rchild;
};

int dp[1005] = {0};
int maxdp = -1;

struct Node * treeInsert(struct Node *root, int tmp){
	if(root == NULL){
		root = new struct Node;
		root->lchild = root->rchild = NULL;
		root->data = tmp;
	}
	else if(tmp <= root->data)
		root->lchild = treeInsert(root->lchild, tmp);
	else
		root->rchild = treeInsert(root->rchild ,tmp);
	return root;
}

void dfs(struct Node *root, int depth){
	if(root == NULL){
		maxdp = depth > maxdp ? depth : maxdp;
		return ;
	}
	dp[depth]++;
	dfs(root->lchild, depth+1);
	dfs(root->rchild, depth+1);
	delete root;
}

int main(){
	int N, tmp;
	freopen("data.in", "r", stdin);
	scanf("%d", &N);
	struct Node *root = NULL;
	for(int i = 0; i < N; ++i){
		scanf("%d", &tmp);
		root = treeInsert(root, tmp);
	}
	dfs(root, 0);
	printf("%d + %d = %d\n", dp[maxdp-1], dp[maxdp-2], dp[maxdp-1] + dp[maxdp-2]);
	return 0;
}