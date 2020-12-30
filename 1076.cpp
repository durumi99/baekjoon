#include <iostream>
#include <string>
using namespace std;


int main() {
	string tmp;
	string color[10] ={"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
	int res = 0;
	int ohm[3];
	for(int i = 0; i < 3;i++){
		cin >> tmp;
		for(int j = 0 ; j < 10;j++)
			if(color[j] == tmp )
				ohm[i]  = j; 
	}
	res = ohm[0]*10+ohm[1];
	if(res == 0){
		cout << 0 << endl;
		return 0;
	}
	else {
		cout << res;
		for(int i = 0 ; i < ohm[2];i++)
			cout << 0;
		cout << endl;
	}
	return 0;
}