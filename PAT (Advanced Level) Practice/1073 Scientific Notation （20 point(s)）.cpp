#include <iostream>
using namespace std;

int main(){
	// freopen("data.in", "r", stdin);
	string s, m, n;
	int bit, rear;
	cin >> s;
	if(s[0] == '-') printf("-");
	m = s.substr(1,s.find('E')-1);
	rear = m.substr(2).length();
	m = m.substr(0,1) + m.substr(2);
	n = s.substr(s.find('E')+1);

	bit = stoi(n.substr(1));
	if(n[0] == '-'){
		m.insert(0, bit-1, '0');
		if(bit >=1)
			m.insert(0, "0.");
	}
	else if (rear > bit){
		m.insert(bit+1, 1, '.');
	}
	else{
		m.insert(m.length(), bit-rear, '0');
	}
	cout << m << endl;
	
	return 0;
}