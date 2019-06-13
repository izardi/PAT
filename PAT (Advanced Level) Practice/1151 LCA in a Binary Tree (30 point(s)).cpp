#include <cstdio>
#include <map>

int inO[10005], preO[10005], Father[10005] = {0};
std::map<int, int> hash;
std::map<int, int> hash1;

void buildTree(int inL, int preL, int len, int preR){
    if(len == 0) return;

    int root = preO[preL];
    Father[root] = preR;

    int i = 0;
    for(i = inL; i < inL + len; ++i)
        if(root == inO[i])
            break;

    int L = i - inL;
    buildTree(inL, preL+1, L, root);
    buildTree(inL+L+1, preL+L+1, len-1-L, root);
}


void lca(int v1, int v2){
	int tab[10005] = {0};
	int tmp = hash[v1];
	while(tmp != -1){
		tab[tmp] = 1;
		tmp = Father[tmp];
	}
	tmp = hash[v2];
	while(!tab[tmp])
		tmp = Father[tmp];

    if(tmp == hash[v1] || tmp == hash[v2])
        printf("%d is an ancestor of %d.\n", hash1[tmp], tmp == hash[v1] ? v2 : v1);
    else printf("LCA of %d and %d is %d.\n", v1, v2, hash1[tmp]);
}

int main(){
    int M, N, v1, v2, tmp;
    //freopen("d.txt", "r", stdin);
    scanf("%d %d", &M, &N);
    for(int i = 1; i <= N; ++i){ scanf("%d", &tmp); hash1[i] = tmp; hash[tmp] = i; inO[i] = i;}
    for(int i = 1; i <= N; ++i) { scanf("%d", &tmp); preO[i] = hash[tmp];}

    buildTree(1, 1, N, -1);

	while(M--){
        scanf("%d %d", &v1, &v2);
        if( hash[v1] == 0){
            if(hash[v2] == 0){
                printf("ERROR: %d and %d are not found.\n", v1, v2);
            }
            else printf("ERROR: %d is not found.\n", v1);
        }
        else if(hash[v2] == 0){
            printf("ERROR: %d is not found.\n", v2);
        }
        else{
            lca(v1, v2);
        }
    }
    return 0;
}