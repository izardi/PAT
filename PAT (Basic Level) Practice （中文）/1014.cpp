#include <cstdio>
#include <cctype>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    char arr[4][61];
    char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int i;
    for(i = 0; i < 4; ++i)
        scanf("%s", arr[i]);

    for(i = 0 ;; ++i){
        if(arr[0][i] == arr[1][i] && arr[0][i] >= 'A' && arr[0][i] <= 'G'){
            printf("%s ", week[int(arr[0][i] - 'A')]);
            break;
        }
    }
    for(++i;; ++i){
        if(arr[0][i] == arr[1][i]){
            if((arr[0][i]) >= '0' && arr[0][i] <= '9'){
                printf("0%d:", int(arr[0][i] - '0'));
                break;
            }
            if(arr[0][i] >= 'A' && arr[0][i] <= 'N'){
                printf("%d:", int(arr[0][i] -'A' + 10));
                break;
            }
        }
    }
    for(i = 0;; ++i)
        if(arr[2][i] == arr[3][i] && isalpha(arr[2][i])){
            printf("%02d", i);
            break;
        }
    return 0;
}
