#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main(){
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    char arr[101];

    while(N--){
        map<char, int> m;
        int p = 0, t = 0;
        scanf("\n%s", arr);
        for(int i = 0; i < strlen(arr); ++i){
            m[arr[i]]++;
            if(arr[i] == 'P') p = i;
            if(arr[i] == 'T') t = i;
        }
        if(m['P'] == 1 && m['T'] == 1 && m.size() == 3 && t-p != 1 && p * (t-p-1) == int(strlen(arr))-t-1)
            printf("YES\n");
        else printf("NO\n");
    }
}
//这个就是 你不要管  a,b,c为什么是小写 你要看 a,b,c其实就是a,b,c个A ，这就还是乘法啊。你看 aPbTc 是不是只有一个 a,一个 b ,一个 c   那么不就是 APATA  不就是 1*1==1 吗？ 然后我们看 aPbATca  我们把 a,b,c都换成A看看就是