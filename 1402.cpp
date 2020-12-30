#include <iostream>

using namespace std;

bool div(string n ,int f){
	int tmp = 0;
	for(int i = 0 ; i < n.length(); i++)
		tmp = (tmp * 10 +(n[i]-'0'))% f;
	if(tmp == 0)
		return true;
	else
		return false;
}
int main() {
	string n;
	int f;
	cin >> n;
	cin >> f;
	int len = n.length();
	n[len-1] = n[len-2] = '0';
	for(int i = 0 ; i < 10; i++){
		for(int j = 0 ; j < 10; j++){
			n[len-2] = i+ '0';
			n[len-1] = j+ '0';
			if(div(n,f)){
				cout << n[len-2] << n[len-1] << endl;
				return 0;
			}
		}
	}
	return 0;
}