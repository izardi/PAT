#include <cstdio>
int main(){
    char ch[5] = {'S', 'H', 'C', 'D', 'J'};
    int order[54], squence[54];
    int N, i;
    scanf("%d",&N);
    for(i = 0; i < 54; i++){
        scanf("%d", &squence[i]);
        order[i] = i;
    }
    while(N--){
        int newOrder[54];
        for(i = 0; i < 54; i++)
            newOrder[squence[i]-1] = order[i];
        for(i = 0; i < 54; i++)
            order[i] = newOrder[i];
    }
    for(i = 0; i < 54; i++){
        printf("%c",ch[order[i]/13]);
        printf("%d",order[i]%13+1);
        if(i < 53)
            printf(" ");
    }
    return 0;
}
