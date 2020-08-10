#include <cstdio>
#include <cstring>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    char A[101], B[101];
    char s[] = {"0123456789JQK"};

    scanf("%s %s", A, B);
    int tmp, i;
    for(i = 0; i < strlen(B) && i < strlen(A); ++i){
        int ib = strlen(B) - i - 1;
        int ia = strlen(A) - i - 1;
        if(i % 2 != 0){
            tmp = B[ib] - A[ia];
            if(tmp < 0) tmp += 10;
            B[ib] = s[tmp];
            A[ia] = B[ib];
        }
        else{
            B[ib] = s[(B[ib]-'0'+A[ia]-'0')%13];
            A[ia] = B[ib];
        }
    }
    if(strlen(A) > strlen(B)){
        for(; i < strlen(A); ++i){
            int ia = strlen(A) - i - 1;
            if(i % 2 != 0){
                tmp = (A[ia] - '0');
                if(tmp != 0)
                    tmp = 10 - tmp;
                A[ia] = s[tmp];
            }
        }
        printf("%s", A);
    }
    else printf("%s", B);
    return 0;
}
