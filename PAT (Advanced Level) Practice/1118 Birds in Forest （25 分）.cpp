#include <cstdio>
int tree[10005] = {0};
int hash[10005] = {0};

int findFather(int x){
	int a = x;
	while( x != tree[x] ){
		x = tree[x];
	}
	while( a != tree[a] ){
		int z = a;
		a = tree[a];
		tree[z] = x;
	}
	return x;
}

void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB)
		tree[faA] = faB;
}

int main(){
	freopen("data.in", "r", stdin);
	int N, k, B, fB;
	scanf("%d", &N);
	for(int i = 1; i <10005; ++i)
		tree[i] = i;

	for(int i = 1; i <= N; ++i){
		scanf("%d %d", &k, &fB);
		hash[fB] = 1;
		for(int j = 1; j < k; ++j){
			scanf("%d", &B);
			hash[B] = 1;
			Union(fB, B);
		}
	}

	int birds = 0, trees = 0;
	int cnt[10005] = {0};
	for(int i = 1; i < 10005; ++i){
		if(hash[i]){
		 	++birds;
		 	cnt[findFather(i)]++;
		 }
	}
	for(int i = 1; i < 10005; ++i){
		if( cnt[i] != 0)
			++trees;
	}

	printf("%d %d\n", trees, birds);

	scanf("%d", &k);
	int b1, b2;
	for(int i = 0; i < k; ++i){
		scanf("%d %d", &b1, &b2);
		if( findFather(b1) == findFather(b2) )
			printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}