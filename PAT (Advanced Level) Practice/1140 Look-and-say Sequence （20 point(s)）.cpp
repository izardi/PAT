#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int D, N;
    scanf("%d %d", &D, &N);
    vector<int> origin;
    origin.push_back(D);

    for(int i = 1; i < N; ++i){
        vector<int> tmp;
        int cur = origin[0];
        int cnt = 1;
        for(int j = 1; j < origin.size(); ++j){
            if(cur == origin[j])
                ++cnt;
            else{
                tmp.push_back(cur);
                tmp.push_back(cnt);
                cnt = 1;
                cur = origin[j];
            }
        }
        tmp.push_back(cur);
        tmp.push_back(cnt);
        origin = tmp;
    }

    for(int i = 0; i < origin.size(); ++i)
        printf("%d", origin[i]);
    return 0;
}
