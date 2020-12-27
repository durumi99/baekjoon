#include <iostream>
using namespace std;

int main() {
	int n,tmp,tmp2;
	cin >> n;
	bool ary[3] = {true,false,false};
	for(int i = 0 ; i < n ; i++){
		cin >> tmp >> tmp2;
		if(ary[tmp-1] || ary[tmp2-1]){
			ary[tmp-1] = !ary[tmp-1];
			ary[tmp2-1] = !ary[tmp2-1];
		}
	}
	for(int i = 0 ; i < 3 ; i++){
		if(ary[i] == true){
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}