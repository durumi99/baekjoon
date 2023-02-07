#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int N; cin >> N;
	for(int i = N ; i >= 1 ; i--) {
        for(int j = 0 ; j < (N-i) ; j++)
            cout << ' ';
        for(int j = 0 ; j < i*2-1 ; j++)
            cout << '*';
            
	    cout << '\n'; 
	}
	for(int i = 2 ; i <= N ; i++) {
        for(int j = 0 ; j < (N-i) ; j++)
            cout << ' ';
        for(int j = 0 ; j < i*2-1 ; j++)
            cout << '*';
            
        cout << '\n'; 
	}
	return 0;
}