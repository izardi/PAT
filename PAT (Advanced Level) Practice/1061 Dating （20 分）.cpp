#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
int main(){
    char w[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char str[4][61];
    scanf("%s %s %s %s", str[0], str[1], str[2], str[3]);
    int i = 0;
    int k = min(strlen(str[0]), strlen(str[1]));

    for(;i < k && (str[0][i] < 'A' || str[0][i] > 'G' || str[1][i] != str[0][i]); ++i);
    printf("%s ", w[int(str[0][i] - 'A')]);
    ++i;

    for(; i < k; ++i){
        if(str[0][i] == str[1][i]){
            if(isdigit(str[0][i])){
                printf("0%d", int(str[0][i] - '0'));
                break;
            }
            if(str[0][i] >= 'A' && str[0][i] <= 'N'){
                printf("%d", int(str[0][i] - 'A') + 10);
                break;
            }
        }
    }
    k = min(strlen(str[2]), strlen(str[3]));

    for(i = 0; i < k && (str[2][i] != str[3][i] || !isalpha(str[2][i])); ++i);
    printf(":%02d", i);

    return 0;
}
