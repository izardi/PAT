#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct Node{
    string name;
    string id;
    char gender;
    int grade;
};
int main(){
    int N;
    cin >> N;
    Node tmp, low_male{"", "", 'M', 101}, high_female{"", "", 'F', -1};
    while(N--){
        cin >> tmp.name >> tmp.gender >> tmp.id >> tmp.grade;
        if(tmp.gender == 'M'){
            if(tmp.grade < low_male.grade)
                low_male = tmp;
        }
        else if(tmp.grade > high_female.grade)
            high_female = tmp;
    }
    int flag = 1;
    if(high_female.grade != -1)
        cout << high_female.name << ' ' << high_female.id << endl;
    else{
        cout << "Absent" << endl;
        flag = 0;
    }
    if(low_male.grade != 101)
        cout << low_male.name << ' ' << low_male.id << endl;
    else{
        cout << "Absent" << endl;
        flag = 0;
    }
    if(flag)
        cout << high_female.grade - low_male.grade << endl;
    else cout << "NA" << endl;
    return 0;
}
