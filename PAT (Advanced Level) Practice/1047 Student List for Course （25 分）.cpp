#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int _MAX = 2501;
int hash_name(char *s){
    int res = 0;
    for(int i = 0 ; i < 3; i++){
        res = res* 26 + (s[i] - 'A');
    }
    res = res * 10 + s[3] - '0';
    return res;
}
void printChar(int n){
    char name[5];
    name[3] = n%10 +'0';
    n /= 10;
    for(int i = 2; i >= 0; i--){
        name[i] = n%26 + 'A';
        n /= 26;
    }
    name[4] = '\0';
    printf("%s\n", name);
}

int main(){
    int tmp, N, K, i, num, n;
    char name[5];
    scanf("%d  %d", &N, &K);
    vector<int> array[_MAX];

    for(i = 0; i < N; i++){
        scanf("%s %d", name, &num);
        tmp = hash_name(name);
        for(int j = 0; j < num; j++){
            scanf("%d", &n);
            array[n].push_back(tmp);
        }
    }

    for(i = 1; i <= K; i++){
        printf("%d %d\n", i, array[i].size());
        sort(array[i].begin(), array[i].end());
        for(vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
            printChar(*it);
    }
    return 0;
}
