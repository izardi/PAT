#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
    int l1, l2, i, tmp1, tmp2, result;
    scanf("%d", &l1);
    int a[200001];
    long int tmp;
    for(i = 0; i < l1; i++){
        scanf("%ld", &tmp);
        a[i] = min((long)INT_MAX, tmp);
    }
    scanf("%d", &l2);
    int median = (l1+l2-1)/2;
    l2--;
    scanf("%ld", &tmp);
    tmp2 = min((long)INT_MAX, tmp);
    result = tmp2;
    i = 0;
    tmp1 = a[i++];

    do{
        if( tmp1 > tmp2 ){
            result = tmp2;
            if(l2){
                l2--;
                scanf("%ld", &tmp);
                tmp2 = min((long)INT_MAX, tmp);
            }else{
                while(median--){
                    result = tmp1;
                    tmp1 = a[i++];
                }
                break;
            }
        }
        else{
            result = tmp1;
            if(i < l1){ tmp1 = a[i++];}
            else {
                while(median--){
                    result = tmp2;
                    scanf("%ld", &tmp);
                    tmp2 = min((long)INT_MAX, tmp);
                }
                break;
            }
        }
    } while(median--);

    printf("%d", result);
    return 0;
}
