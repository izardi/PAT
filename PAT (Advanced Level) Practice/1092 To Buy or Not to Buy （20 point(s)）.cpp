#include <cstdio>
#include <cstring>
int main(){
    char shop[10001], eva[10001];
    int hs[128] = {0}, he[128] = {0};
    int c = 0;

    scanf("%s\n%s", shop, eva);

    for(int i = 0; i < strlen(shop); ++i)
        hs[shop[i]]++;

    for(int i = 0; i < strlen(eva); ++i){
        he[eva[i]]++;
        if(hs[eva[i]] < he[eva[i]])
            ++c;
    }
    if(c) printf("No %d\n", c);
    else{
        printf("Yes %d\n", strlen(shop) - strlen(eva));
    }
    return 0;
}
