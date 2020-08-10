#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <unordered_map>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);

    char G[][5] = {"tret", "jan", "feb", "mar", "apr", "may",
        "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

    char S[][4] = {"", "tam", "hel", "maa", "huh", "tou",
        "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    unordered_map<string, int> mp1, mp2;

    for(int i = 0; i < 13; ++i)
        mp1[string(G[i])] = i+1;
    for(int i = 1; i < 13; ++i)
        mp2[string(S[i])] = i;
    char tmp[8];
    char s1[4], s2[4];
    int num;
    while(N--){
        scanf("\n%[^\n]", tmp);  
        if(isdigit(tmp[0])){
            sscanf(tmp, "%d", &num);   
            printf("%s", S[num/13]);
            if(num/13 !=0){
                if(num%13 !=0)
                    printf(" %s", G[num%13]);
            }
            else printf("%s", G[num]);
        }
        else if(strlen(tmp) >= 5 ){
            sscanf(tmp, "%s %s", s1, s2);
            printf("%d", mp2[string(s1)]*13+mp1[string(s2)]-1);
        }
        else{
            if(mp1[string(tmp)]){
                printf("%d", mp1[string(tmp)]-1);
            }
            else printf("%d", mp2[string(tmp)]+12);
        }
        printf("\n");
    }
    return 0;
}
