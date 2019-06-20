#include <cstdio>
#include <cmath>
using namespace std;

long int gcd(long int x, long int y){
    if(y == 0) return x;
    if(x < y) return gcd(y, x);
    else return gcd(y, x%y);
}

void print(long int x, long int y){
    if(y == 0){
        printf("Inf");
        return;
    }
    if(x == 0){
        printf("0");
        return;
    }
    if(y < 0){
        y *=-1;
        x *= -1;
    }
    if(x < 0)
        printf("(");
    long int g = gcd(abs(x), y);
    x /= g; y /= g;
    long int tmp = x / y;
    if(abs(tmp) > 0){
        if(x % y == 0)
            printf("%ld", x / y);
        else printf("%ld %ld/%ld", tmp, (long int)abs(x) % y, y);
    }
    else printf("%d/%ld", x, y);

    if(x < 0)
        printf(")");
}

int main(){
    long int a1, b1, a2, b2;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    
    print(a1, b1); printf(" + "); print(a2, b2); printf(" = "); print(a1*b2+a2*b1, b1*b2); printf("\n");
    print(a1, b1); printf(" - "); print(a2, b2); printf(" = "); print(a1*b2-a2*b1, b1*b2); printf("\n");
    print(a1, b1); printf(" * "); print(a2, b2); printf(" = "); print(a1*a2, b1*b2); printf("\n");
    print(a1, b1); printf(" / "); print(a2, b2); printf(" = "); print(a1*b2, b1*a2); printf("\n");
    return 0;
}
