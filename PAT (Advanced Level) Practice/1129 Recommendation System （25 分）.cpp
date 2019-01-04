#include <cstdio>
#include <set>
using namespace std;
struct node{
	int data, cnt;
	bool operator < (const node &a) const{
		return (cnt != a.cnt) ? cnt > a.cnt : data < a.data;
	}
};

int main(){
	// freopen("data.in", "r", stdin);
	int i, N, K, num, book[50005] = {0};
	scanf("%d %d", &N, &K);
	set<node> S;
	for(i = 0; i < N; ++i){
		scanf("%d", &num);
		if(i != 0){
			printf("%d:", num);
			int tmpCnt = 0;
			for(set<node>::iterator it = S.begin(); tmpCnt < K & it != S.end(); ++it){
				printf(" %d", it->data);
				++tmpCnt;
			}
			printf("\n");
		}
		set<node>::iterator it = S.find(node{num, book[num]});
		if(it != S.end()) S.erase(it);
		++book[num];
		S.insert(node{num, book[num]});
	}
	return 0;
}