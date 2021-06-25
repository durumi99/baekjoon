#include <iostream>
using namespace std;

int main() {
	string ary = "-\\(@?>&%";
	string tmp;
	int sum;
	while(true){
		cin >> tmp;
		if(tmp == "#"){
			break;
		}
		sum = 0;
		for(int i = 0 ; i < tmp.size();i++){
			if(tmp[i] == '/')
				sum += -1;
			else
				for(int j = 0 ; j < 8 ; j++)
					if(ary[j] == tmp[i])
						sum += j;
			sum *= 8;
		}
		sum /= 8;
		cout << sum << endl;
	}
	
	return 0;
}