#include <iostream>

using namespace std;

int main() {
	int tmp;
	bool as = true,des = true;
	for(int i = 1 ; i <=8; i++){
		cin >> tmp;
		if(tmp != i)
			as = false;
		if(tmp != 9-i)
			des = false;
	}
	if(as){
		cout << "ascending" << endl;
		return 0;
	}
	else if(des){
		cout << "descending" << endl;
		return 0;
	}
	else
		cout << "mixed" << endl;
	return 0;
}