#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(){
//    freopen("data.in", "r", stdin);
    int N;
    scanf("%d\n", &N);
    char str[20];
    char s1[20], s2[20];
    
    while(N--){
        scanf("%s", str);
        if(strlen(str) <= 1){
            printf("No\n");
            continue;
        }
        
        int j = 0;
        for(j = 0; j < strlen(str)/2; ++j)
            s1[j] = str[j];
        s1[j] = '\0';
        for(j = strlen(str)/2; j < strlen(str); ++j)
            s2[j-strlen(str)/2] = str[j];
        s2[strlen(str)/2] = '\0';
//        printf("%d %d %d\n", atoi(s1), atoi(s2), atoi(str));
        if((atoi(s1) * atoi(s2)) != 0){ 
            if(atoi(str) % (atoi(s1) * atoi(s2)) == 0){
                printf("Yes\n");
                continue;
            }
        } 
        printf("No\n");
    }
    return 0;
}
