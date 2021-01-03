#include <iostream>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m , n;
	cin >> m >> n;
	int a[1000000];
	for(int i = 2 ; i <= n ; i++) {
        a[i] = i;
    }
    for(int i = 2 ; i <= n ; i++){
    	if(a[i] == 0)
    		continue;
    	for(int j = 2*i; j <= n ; j += i)
    		a[j] = 0;
    }
    for(int i = m ; i <= n ;i++)
    	if(a[i] != 0)
    		cout << a[i] << '\n';
	return 0;
}