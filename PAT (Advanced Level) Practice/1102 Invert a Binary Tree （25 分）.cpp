#include <cstdio>
#include <queue>
using namespace std;

struct Node{
	int lchild, rchild;
} node[11];
int flag = 1;

void inOrderTraversal_invert(int root){
	if(root != -1){
		inOrderTraversal_invert(node[root].rchild);
		if(flag){
			printf("%d", root);
			flag = 0;
		} else printf(" %d", root);
		inOrderTraversal_invert(node[root].lchild);
	}
}
int main(){
	int N;
	scanf("%d", &N);
	int hash[11] = {0};
	for(int i = 0; i < N; ++i){
		char tmp1, tmp2;
		scanf("\n%c %c", &tmp1, &tmp2);
		if(tmp1 != '-'){
			node[i].lchild = tmp1 - '0';
			hash[tmp1 - '0'] = 1;
		}
		else
			node[i].lchild = -1;
		if(tmp2 != '-'){
			node[i].rchild = tmp2 - '0';
			hash[tmp2 - '0'] = 1;
		}
		else
			node[i].rchild = -1;
	}

	int root;
	for(int i = 0; i < N; ++i)
		if(!hash[i]){
			root = i;
			break;
		}

	queue<int> que;
	que.push(root);
	while(!que.empty()){
		int tmp = que.front();
		que.pop();
		if(node[tmp].rchild != -1)
			que.push(node[tmp].rchild);
		if(node[tmp].lchild != -1)
			que.push(node[tmp].lchild);
		if(flag){
			printf("%d", tmp);
			flag = 0;
		}else printf(" %d", tmp);
	}
	printf("\n");
	flag = 1;
	inOrderTraversal_invert(root);
	return 0;
}