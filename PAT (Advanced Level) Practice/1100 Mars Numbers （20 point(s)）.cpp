#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string a[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string b[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void toMars(int n){
    if(n > 12){
        printf("%s", b[n/13].c_str());
        if(n % 13 != 0)
            printf(" %s\n", a[n%13].c_str());
        else printf("\n");
    }
    else
        printf("%s\n", a[n].c_str());
}

void toEarth(string & s){
    int sum = 0, i = 0;
    if(s.length() > 4){
        while(s.substr(0,3) != b[i])
            ++i;
        sum += i*13;
        i = 0;
        while(s.substr(4) != a[i])
            ++i;
        sum += i;
    }
    else{
        while(i < 13 && s != a[i]) ++i;
        if(i == 13){
            i = 0;
            while(s != b[i]) ++i;
            sum = i*13;
        }
        else sum = i;
    }
    printf("%d\n", sum);
}

int main(){
    int N;
    scanf("%d\n", &N);
    string s;
    while(N--){
        getline(cin, s);
        if(isdigit(s[0]))
            toMars(stoi(s));
        else toEarth(s);
    }
    return 0;
}
