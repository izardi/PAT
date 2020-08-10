#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    //freopen("in", "r", stdin);
    string str;
    cin >> str;
    int i = 0;
    while(str[i] != 'E') ++i;
    if(str[0] == '-') cout << "-";
    string s1 = str.substr(1, i-1);
    int exp = stoi(str.substr(i+1));

    if(exp >= 0){
        cout << s1[0];
        int i;
        for(i = 0; i+2 < s1.length() && i < exp; ++i){
            cout << s1[i+2];        
        }
        if(i+2 < s1.length()){
            cout << ".";
            for(; i+2 < s1.length(); ++i)
                cout << s1[i+2];
        }
        else if(i< exp){
            for(; i < exp; ++i)
                cout << "0";
        }
    }
    else{
        cout << "0.";
        int i;
        exp *= -1;
        for(i = 1; i < exp; ++i)
            cout << "0";
        for(i = 0; i < s1.length(); ++i)
            if(s1[i] != '.') cout << s1[i];
    }
    return 0;
}
