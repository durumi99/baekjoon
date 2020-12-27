#include <iostream>
using namespace std;

int main() {
	int width[10] = {4,2,3,3,3,3,3,3,3,3};
	int sum = 0;
	string tmp;
	while(true){
		cin >> tmp;
		if(tmp == "0")
			break;
		sum = 1;
		for(int i = 0 ; i < tmp.size(); i++){
			sum += width[tmp[i]-'0']+1;
		}
		cout << sum << endl;
	}
	return 0;
}