#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int data, lchild, rchild;
} node[101];
int data[101];
int cnt = 0;

void inOrderTraversal(int root){
	if(root != -1){
		inOrderTraversal(node[root].lchild);
		node[root].data = data[cnt++];
		inOrderTraversal(node[root].rchild);
	}
}

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; ++i)
		scanf("%d %d", &node[i].lchild, &node[i].rchild);

	for(int i = 0; i < N; ++i)
		scanf("%d", &data[i]);

	sort(data, data+N);
	inOrderTraversal(0);
	queue<int> que;
	que.push(0);
	int flag = 1;
	while(!que.empty()){
		int tmp = que.front();
		que.pop();
		if(node[tmp].lchild != -1)
			que.push(node[tmp].lchild);
		if(node[tmp].rchild != -1)
			que.push(node[tmp].rchild);
		if(flag){
			printf("%d", node[tmp].data);
			flag = 0;
		}
		else
			printf(" %d", node[tmp].data);

	}
	return 0;
}