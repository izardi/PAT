#include <iostream>
#include <cstring>
using namespace std;
bool isSymmetric(char* star, int len){
    for(int i = 0; i < len/2; i++)
        if(*(star+i) != *(star+len-i-1))
            return false;
    return true;
}
int main(){
    char str[1002];
    cin.getline(str, 1002);
    int str_len = strlen(str);
    int sub_len = str_len;
    int flag = 0;
    while(sub_len){
        for(int i = 0; i <= str_len - sub_len; i++)
            if(isSymmetric(str+i, sub_len)){
                flag = 1;
                break;
            }
        if(flag) break;
        sub_len--;
    }
    printf("%d", sub_len);
    return 0;
}
