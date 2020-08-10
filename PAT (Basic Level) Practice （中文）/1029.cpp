#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <cctype>
using namespace std;

int main(){
    freopen("in", "r", stdin);
    char a[81], b[81];
    scanf("%s\n%s", a, b);
    char res[50]; 
    int cnt = 0, j = 0;
    unordered_map<char, int> mp;
    for(int i = 0; i < strlen(b); ++i)
        mp[toupper(b[i])] = 1;
    for(int i = 0; i < strlen(a); ++i){
        if(!mp[toupper(a[i])]){
            mp[toupper(a[i])] = 1;
            printf("%c", toupper(a[i]));
        }
    }
    return 0;
}
