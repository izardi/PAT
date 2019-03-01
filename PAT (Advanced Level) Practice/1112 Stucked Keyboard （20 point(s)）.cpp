#include <cstdio>
#include <cstring>

int main(){
    int k;
    char s[1001];
    scanf("%d\n%s", &k, s);

    int cnt = 1;
    int ascii[129] = {0};
    char cur = s[0];
    for(int i = 1; i < strlen(s); ++i){
        if(cur == s[i]){
            cnt++;
        }else{
            ascii[cur] = 2;
            cur = s[i];
            cnt = 1;
        }
        if(cnt == k){
            if(ascii[cur] != 2)
                ascii[cur] = 1;
            if(i != strlen(s)-1){
                cur = s[i+1];
                cnt = 0;
            }
        }
    }
    int hash[128] = {0};
    for(int i = 0; i < strlen(s); ++i){
        if(ascii[s[i]] == 1 && hash[s[i]] == 0){
            printf("%c", s[i]);
            hash[s[i]] = 1;
        }
    }

    printf("\n");
    
    for(int i = 0; i < strlen(s);){
        if(hash[s[i]] == 1){
            printf("%c", s[i]);
            i += k;
        }else{
            printf("%c", s[i]);
            ++i;
        }
    }
    
    return 0;
}
