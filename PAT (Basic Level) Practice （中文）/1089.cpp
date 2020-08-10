#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    int N, v[102];
    freopen("in", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &v[i]);
    for(int i = 1; i <= N; ++i){
        for(int j = i+1; j <= N; ++j){
            vector<int> lie, a(N+1, 1);
            a[i] = a[j] = -1;
            for(int k = 1; k <=N; ++k)
                if(v[k] *a[abs(v[k])] < 0) lie.push_back(k);
            if(lie.size() == 2 && a[lie[0]] * a[lie[1]] < 0){
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}
