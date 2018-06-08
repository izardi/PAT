#include <cstdio>

typedef struct RNode {
    int login;
    int logout;
    char name[16];
} Record;

int main(){
    int M;
    scanf("%d", &M);
    Record lock, unlock, tmp;
    int hour, minute, second;
    scanf("%s %d:%d:%d", tmp.name, &hour, &minute, &second);
    tmp.login = hour*10000 + minute*100 + second;
    scanf("%d:%d:%d", &hour, &minute, &second);
    tmp.logout = hour*10000 + minute*100 + second;
    lock = unlock = tmp;
    while(--M){
        scanf("%s %d:%d:%d", tmp.name, &hour, &minute, &second);
        tmp.login = hour*10000 + minute*100 + second;
        scanf("%d:%d:%d", &hour, &minute, &second);
        tmp.logout = hour*10000 + minute*100 + second;
        if(tmp.login < unlock.login)
            unlock = tmp;
        if(tmp.logout > lock.logout)
            lock = tmp;
    }
    printf("%s %s", unlock.name, lock.name);
    return 0;
}