#include <bits/stdc++.h>

using namespace std;

string str;

int isPalindrome(int left, int right, int res) {
  
    while(left < right) {
        if(str[left] != str[right]) {
        	if(res == 0) {
	            if(isPalindrome(left+1, right, 1) == 0 || isPalindrome(left, right-1, 1) == 0) {
	            	return 1;
	            } else {
	            	return 2;
	            }
        	} else {
        		return 2;
        	}
        } else {
        	left++;
        	right--;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC; cin >> TC;
    while(TC--) {
    	cin >> str;
    	int res = isPalindrome(0, str.length()-1, 0);
    	cout << res << '\n';
    }
    
    return 0;
}