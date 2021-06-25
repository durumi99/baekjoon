#include <iostream>
using namespace std;

int main() {
	string input;
	cin >> input;
	int count = 0;

	for(int i = 0 ; i < input.size()-1 ; i++)
		if(input[i] != input[i+1])
			count++;
	if(count == 0 || count == 1)
		cout << count;
	else
		if(count %2)
			cout << (count+1)/2;
		else
			cout << count /2;
	
	return 0;
}