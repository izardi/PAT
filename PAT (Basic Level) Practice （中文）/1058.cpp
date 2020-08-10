#include <cstdio>
#include <vector>
#include <set>
using namespace std; 

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    
    int score[101];
    int a[101], tmp, k;
    char ch;
    vector<set<char> > ans(M+1);
    for(int i = 1; i <= M; ++i){
        scanf("%d %d %d", &score[i], &tmp, &k);
        for(int j = 0; j < k; ++j){
            scanf(" %c", &ch);
            ans[i].insert(ch);
        }
    }
    int wr[101] = {0};
    getchar();
    int max = 0;
    while(N--){
        int res = 0;
        for(int i = 1; i <= M; ++i){
            scanf("(%d", &k);
            int flag = 1;
            for(int j = 0; j < k; ++j){
                scanf(" %c", &ch);
                if(flag && (ans[i].size() != k ||
                ans[i].find(ch) == ans[i].end())){
                    ++wr[i];
                    if(wr[i] > wr[max]) max = i;
                    flag = 0;
                }
            } 
            getchar();getchar();
            if(flag) res += score[i];
        }
        printf("%d\n", res);
    }
    if(wr[max]){
        printf("%d", wr[max]);
        for(int i = 1; i <= M; ++i){
            if(wr[i] == wr[max]){
                printf(" %d", i);
            }
        }
    }
    else printf("Too simple");
    return 0;
}
