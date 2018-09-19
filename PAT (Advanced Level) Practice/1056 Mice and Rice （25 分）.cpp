#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int NP, NG, i;
    scanf("%d %d", &NP, &NG);
    int mice[NP], res[NP] = {0};
    for(i = 0; i < NP; i++)
        scanf("%d", &mice[i]);

    vector<int> order(NP);
    for(i = 0; i != NP; ++i)
        scanf("%d", &order[i]);
    vector<int> next(NP);

    while(order.size() > 1){
        int n = 0;
        next.clear();
        int curridx = order.size()/NG + 1;
        if(order.size() % NG) ++curridx;
        while(n < order.size()){
            int max = -1, idx = 0;
            for(i = 0; i < NG && n < order.size(); ++i, ++n){
                res[order[n]] = curridx;
                if(mice[order[n]] > max){
                    max = mice[order[n]];
                    idx = order[n];
                }
            }
            next.push_back(idx);
        }
        order = next;
    }
    res[order[0]] = 1;
    printf("%d", res[0]);
    for(i = 1; i < NP; i++)
        printf(" %d", res[i]);

    return 0;
}
