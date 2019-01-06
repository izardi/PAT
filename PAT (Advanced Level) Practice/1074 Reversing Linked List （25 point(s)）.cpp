#include <cstdio>

struct Node{
	int data;
	int next;
}List[100005];

int main(){
	int head, N, K, tmp;
	scanf("%d %d %d", &head, &N, &K);
	for(int i = 0; i < N; ++i){
		scanf("%d", &tmp);
		scanf("%d %d", &List[tmp].data, &List[tmp].next);
	}
	
	while(head != -1){
		printf("%d %d %d\n", head, List[head].data, List[head].next);
		head = List[head].next;
	}
	return 0;
}