#include <iostream>
using namespace std;

int main() {
	int input,max=0,tmp;
	for(int i = 0 ; i < 9;i++){
		cin >> input;
		if(input > max){
			max = input;
			tmp = i;
		}
	}
	
	cout << max << endl << tmp+1 ;
	return 0;
}