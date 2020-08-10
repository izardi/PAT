#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node{
    char id[14];
    int score;
}S[10005];
struct R{
    int num = 0;
    int ts = 0;
}Ro[1000];
bool cmp(Node a, Node b){
    if(a.score != b.score)
        return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N, M;
    int t, room, data;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("\n%s %d", S[i].id, &S[i].score);
        int tmp = 0;
        for(int j = 1; j < 4; ++j)
            tmp = tmp*10 + S[i].id[j]-'0';
        ++Ro[tmp].num; 
        Ro[tmp].ts += S[i].score;
    }
    
    char l;
    for(int i = 1; i <= M; ++i){
        scanf("%d ", &t);
        printf("Case %d: %d", i, t);
        if(t == 1){
            scanf("%c", &l);  
            printf("%c\n", l);
            int flag = 0;
            for(int j = 0; j < N; ++j){
                if(S[j].id[0] == l){
                    printf("%s %d\n", S[j].id, S[j].score);
                    flag = 1;
                } 
            }
            if(!flag) printf("NA\n");
        }
        else if(t == 2){
            scanf("%d\n", &room);
            printf("%03d", room);
            if(Ro[room].num == 0){
                printf("NA\n");
                continue;
            }
            printf("%d %d", Ro[room].num, Ro[room].ts);
        }
        else{
            scanf("%d", &data);   
            printf("%d\n", data);
            for(int j = 0; j <= 999; ++j){
                for(Ro[j].num != 0){
                    int tmp = 0;
                    
                }
            }
        }
    }
    
    return 0;
}
