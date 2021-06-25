#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int answer = 0 ,tmp;
	for(int i = 0  ; i < 5 ; i++){
		cin>>tmp;
		answer += (tmp*tmp);
	}
	cout<< answer%10;
	return 0;
}