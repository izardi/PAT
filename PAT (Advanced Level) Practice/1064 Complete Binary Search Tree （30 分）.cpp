#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

static int array[1001], res[1002];

void solve(int len, int root, int s){
    if(len <= 0) return;
    else if(len == 1){
        res[root] = array[s];
        return;
    }
    int left, right, level;
    level = int(log(len)/log(2));
    int maxn = (int)pow(2, level-1);
    left = right = maxn - 1;
    int remin = len - (left + right + 1);
    if(remin <= maxn) left += remin;
    else { left += maxn; right += (remin - maxn);}
    res[root] = array[s + left];
    solve(left, root*2, s);
    solve(right, root*2+1, s+left+1);
}

bool cmp(const int &a, const int &b){
    return a < b;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &array[i]);
    sort(array, array + N, cmp);

    solve(N, 1, 0);
    printf("%d", res[1]);
    for(int i = 2; i <= N; ++i)
        printf(" %d", res[i]);
    return 0;
}
