#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 666 ; i <= 2666799;i++){
		if( to_string(i).find("666") != -1){
			n--;
			if(n == 0){
				cout << i;
				return 0;
			}
		}
	}
		
	return 0;
}