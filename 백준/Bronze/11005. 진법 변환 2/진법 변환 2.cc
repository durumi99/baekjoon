#include <iostream>
#include <stack>

using namespace std;


char cvt(int n) {
    if(n < 10) {
        return n+'0';
    } else {
        return 'A'+(n-10);
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int N, B; cin >> N >> B;
	stack <char> s;
	while(N) {
	    char tmp = cvt(N%B);
	    s.push(tmp);
	    N /= B;
	}
	while(!s.empty()){
	    cout << s.top();
	    s.pop();
	}
	return 0;
}