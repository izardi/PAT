#include <cstdio>

const int MAXLEN = 1001;

int main(){
    double Polynomial1[MAXLEN] = {0.0};
    double Polynomial2[MAXLEN] = {0.0};
    double Polynomial3[2*MAXLEN] = {0.0};
    
    int len1;
    scanf("%d", &len1);
    int exponents1[len1];
    double tmp;
    for(int i = 0; i < len1; i++){
        scanf("%d", &exponents1[i]);
        scanf("%lf", &tmp);
        Polynomial1[exponents1[i]] += tmp;
    }
    
    int len2;
    scanf("%d", &len2);
    int exponents2[len2];
    for(int i = 0; i < len2; i++){
        scanf("%d", &exponents2[i]);
        scanf("%lf", &tmp);
        Polynomial2[exponents2[i]] += tmp;
    }
    
    for(int i = 0; i < len1; i++)
        for(int j = 0; j < len2; j++){
            Polynomial3[exponents1[i] + exponents2[j]] +=
                Polynomial1[exponents1[i]] * Polynomial2[exponents2[j]];
        }
    int cnt = 0;
    for(int i = 0; i < 2*MAXLEN; i++)
        if(Polynomial3[i] != 0.0)
            cnt++;
    printf("%d", cnt);
    if(cnt == 0)
        return 0;
    for(int i = 2*MAXLEN-1; i >= 0; i--){
        if(Polynomial3[i] != 0.0)
            printf(" %d %.1lf", i, Polynomial3[i]);
    }
    return 0;
}