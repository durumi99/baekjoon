#include <iostream>
using namespace std;

int multi(){
	
}
int main() {
	int tmp1,tmp2;
	string n;
	cin >> n;
	int len = n.length();
	for(int i = 0 ; i < len-1; i++){
		tmp1 = tmp2 = 1;
		for(int j = 0 ; j <= i ;j++){
			tmp1 *= (n[j]-'0');
		}
		for(int j = i+1 ; j < len ;j++){
			tmp2 *= (n[j]-'0');
		}
		if( tmp1 == tmp2){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}