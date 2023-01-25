#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[5000001];

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
	string s; getline(cin, s);
	for(int i = 0 ; i < s.length() ; i++) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			// s[i] += 13;
			if(s[i] + 13 > 'Z')
				s[i] -= 13;
			else 
				s[i] += 13;
		} else if(s[i] >= 'a' && s[i] <= 'z') {
			// s[i] += 13;
			if(s[i] + 13 > 'z')
				s[i] -= 13;
			else 
				s[i] += 13;
		}
	}
	
	cout << s;
	return 0;
}