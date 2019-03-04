#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int seq[105];
    for(int i = 1; i <= N; ++i)
        scanf("%d", &seq[i]);
        
    for(int i = 1; i < N; ++i)
        for(int j = i+1; j <= N; ++j){
            vector<int> a(N+1, 1), lie;
            a[i] = a[j] = -1;
            for(int k = 1; k <= N; ++k)
                if(seq[k] * a[abs(seq[k])] < 0) lie.push_back(k);
            if(lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0){
                printf("%d %d", i, j);
                return 0;
            }
        }
    printf("No Solution\n");
    return 0;
}
