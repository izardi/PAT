#include <cstdio>
#include <cstring>

struct Node{
    int modified;
    char name[11];
    char passwd[11];
} array[1001];

bool modifi(char &c){
    if(c == '1'){c = '@'; return true;};
    if(c == '0'){c = '%'; return true;};
    if(c == 'O'){c = 'o'; return true;};
    if(c == 'l'){c = 'L'; return true;};
    return false;
}

int main(){
    int N, cnt;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s %s", array[i].name, array[i].passwd);
        array[i].modified == 0;
        for(int j = 0; j < strlen(array[i].passwd); j++)
            if(modifi(array[i].passwd[j]))
                array[i].modified = 1;
        cnt += array[i].modified;
    }
    
    if(cnt){
        printf("%d\n", cnt);
        for(int i = 0; i < N; i++)
            if(array[i].modified)
                printf("%s %s\n", array[i].name, array[i].passwd);
    }
    else {
        if(N > 1)
            printf("There are %d accounts and no account is modified\n", N);
        else
            printf("There is %d account and no account is modified\n", N);
    }
    return  0;
}