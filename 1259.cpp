#include <iostream>
#include <string>
using namespace std;

int main() {
	bool pal;
	string tmp;
	while(true){
		pal = true;
		cin >> tmp;
		if(tmp == "0")
			break;
		for(int i = 0 ; i < tmp.size() / 2 ; i++){
			if(tmp[i] != tmp[tmp.size() - 1 - i]){
				cout << "no\n";
				pal = false;
				break;
			}
		}
		if(pal)
			cout <<"yes\n";

	}
	return 0;
}