#include <cstdio>
#include <cstring>
#include <cctype>
int main(){
    char s1[81], s2[81];
    scanf("%s\n%s", s1, s2);

    int ascii[128] = {0};

    for(int i = 0; i < strlen(s2); ++i)
        ascii[toupper(s2[i])] = 1;

    for(int i = 0; i < strlen(s1); ++i)
        if(!ascii[toupper(s1[i])]){
            ascii[toupper(s1[i])] = 1;
            printf("%c", toupper(s1[i]));
        }
    return 0;
}
