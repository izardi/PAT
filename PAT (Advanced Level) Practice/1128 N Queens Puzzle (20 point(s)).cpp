#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    //freopen("d.txt", "r", stdin);
    int N, K, tmp;
    scanf("%d", &K);

    while(K--){
        int chessborad[1005] = {0};
        scanf("%d", &N);
        bool res = true;
        for(int i = 1; i <= N; ++i){
            scanf("%d", &chessborad[i]);
            for(int j = 1; j < i; ++j)
                if(chessborad[i] == chessborad[j] || (i - j) == abs(chessborad[i] - chessborad[j])){
                    res = false;
                    break;
                }
        }
        printf("%s\n", res == false ? "NO" : "YES");
    }
    return 0;
}