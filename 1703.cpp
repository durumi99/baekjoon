#include <iostream>
using namespace std;

int main() {
	int input;
	int tmp1,tmp2,sum;
	while(true){
		sum = 1;
		cin >> input;
		if(input == 0)
			break;
		for(int i = 0 ; i < input ; i++){
			cin >> tmp1 >> tmp2;
			sum = sum*tmp1-tmp2;
		}
		cout << sum << endl;
	}
}