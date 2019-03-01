#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(){
    int M, N, S;
    scanf("%d %d %d", &M, &N, &S);
    string name;
    map<string, int> mp;
    int cnt = N-1;
    int flag = 0;
    for(int i = 1; i <= M; ++i){
        cin >> name;
        if(i >= S){
            cnt++;
            if(cnt == N){
                if(mp[name] == 0){
                    mp[name] = 1;
                    cout << name <<endl;
                    flag = 1;
                    cnt = 0;
                }
                else{
                    --cnt;
                }
            }
        }
    }
    if(!flag) cout << "Keep going..." << endl;
    return 0;
}
