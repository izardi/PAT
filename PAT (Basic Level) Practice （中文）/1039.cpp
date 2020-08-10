#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    char ch;
    int hash [128] = {0};
    int cnt = 0;
    int c1 = 0, c2 = 0;
    while((ch = getchar()) != '\n'){
        ++hash[ch];
        ++c1;
    }
    while((ch = getchar()) != '\n'){
        ++c2;
        if(!hash[ch])
            ++cnt;
        else --hash[ch];
    }
    if(cnt) printf("No %d", cnt);
    else printf("Yes %d", c1 - c2);
    return 0;
}
