#include <cstdio>
void printf_fline(int n, char c){
    for(int i = 0; i < n; i ++){
        printf("%c",c);
    }
}
int main(){
    int n = 0;
    char c;
    scanf("%d %c", &n, &c);
    int l = n%2==0 ? n/2 - 2:n/2-1;
    printf_fline(n,c);
    printf("\n");
    for(int i = 0; i < l; i++){
        printf("%c",c);
        for(int j = 0; j < n - 2; j++)
            printf(" ");
        printf("%c\n",c);
    }
    printf_fline(n,c);
    return 0;
}
