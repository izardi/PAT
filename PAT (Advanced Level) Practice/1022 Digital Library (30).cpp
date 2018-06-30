#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node{
    char id[8];
    char title[81];
    char author[81];
    char key_words[5][11];
    int kn;
    char publisher[81];
    char pub_year[5];
} books[10001];

bool cmp(struct Node & a, struct Node & b){
    return strcmp(a.id, b.id) < 0;
}
int main(){
    int N;
    scanf("%d\n", &N);
    int i;
    for(i = 0; i < N; i++){
        scanf("%[^\n]", books[i].id); getchar();
        scanf("%[^\n]", books[i].title);getchar();
        scanf("%[^\n]", books[i].author);getchar();
        books[i].kn = 0;
        do{
            scanf("%s",books[i].key_words[books[i].kn++]);
        } while(getchar() != '\n');
        scanf("%[^\n]", books[i].publisher);getchar();
        scanf("%[^\n]", books[i].pub_year);getchar();
    }
    sort(books, books+N, cmp);
    
    int M;
    scanf("%d", &M);
    for(i = 0; i < M; i++){
        int num;
        char str[81];
        scanf("%d: ", &num);
        scanf("%[^\n]", str);
        printf("%d: %s\n", num, str);
        bool find = false;
        switch(num){
            case 1:
                for(int j = 0; j < N; j++)
                    if(!strcmp(str, books[j].title)){
                        find = true;
                        printf("%s\n", books[j].id);
                    }
                break;
            case 2:
                for(int j = 0; j < N; j++)
                    if(!strcmp(str, books[j].author)){
                        find = true;
                        printf("%s\n", books[j].id);
                    }
                break;
            case 3:
                for(int j = 0; j < N; j++)
                    for(int k = 0; k < books[j].kn; k++)
                        if(!strcmp(str, books[j].key_words[k])){
                            find = true;
                            printf("%s\n", books[j].id);
                        }
                break;
            case 4:
                for(int j = 0; j < N; j++)
                    if(!strcmp(str, books[j].publisher)){
                        find = true;
                        printf("%s\n", books[j].id);
                    }
                break;
            case 5:
                for(int j = 0; j < N; j++)
                    if(!strcmp(str, books[j].pub_year)){
                        find = true;
                        printf("%s\n", books[j].id);
                    }
                break;
            default: break;
        }
        if(!find)
            printf("Not Found\n");
    }
    return 0;
}