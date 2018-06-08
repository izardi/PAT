#include <cstdio>
char str[10][6] = {"zero", "one", "two", "three", "four", "five", "six", 
"seven", "eight", "nine"}; 

int main(){
    char c;
    int sum;
    while(scanf("%c", &c), c != '\n'){
        sum += (c - '0');
    }
    int num[10], i = 0;
    if(sum == 0){
        printf("zero");
        return 0;
    }
    while(sum){
        num[i++] = sum%10;
        sum /= 10;
    }
    for(int j = i-1; j >=0; j--){
        printf("%s", str[num[j]]);
        if(j) printf(" ");
    }
    return 0;
}
