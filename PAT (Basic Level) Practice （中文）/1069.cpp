#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int M, N, S;
    char s[22];
    scanf("%d %d %d", &M, &N, &S);
    if(S > M) {printf("Keep going..."); return 0;}
    M -= (S-1);
    while(--S){ scanf("\n%s", s);}

    unordered_map<string, int> mp;
    int cnt = -1;
    while(M--){
        scanf("\n%s", s);
        ++cnt;
        if(cnt % N == 0){
            if(!mp[string(s)]){
                printf("%s\n", s);
                mp[string(s)] = 1;
            }
            else --cnt;
        }
    }
    return 0;
}
