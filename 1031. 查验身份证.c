#include <stdio.h>

int main() {
    int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2,};
    char keygen[11] = {"10X98765432"};
    int N;
    int isAllpass = 1;
    scanf("%d", &N);
    while(N--){
        char tmp[18];
        scanf("%s", tmp);
        int sum = 0;
        for(int i =0; i< 17; i++){
            sum += ((tmp[i] - '0')*weight[i]);
        }
        int z = sum%11;
        if(keygen[z] != tmp[17]){
            printf("%s\n",tmp);
            isAllpass = 0;
        }
    }
    if (isAllpass)
        printf("All passed");
    return 0;
}