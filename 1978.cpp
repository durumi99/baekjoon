#include <iostream>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a[1000];
	for(int i = 2 ; i <= 1000 ; i++) {
        a[i] = i;
    }
    for(int i = 2 ; i <= 1000 ; i++){
    	if(a[i] == 0)
    		continue;
    	for(int j = i*i; j <= 1000 ; j += i)
    		a[j] = 0;
    }
	int n,tmp,cnt = 0;
	cin >> n;
	for(int i = 0 ; i < n;i++){
		cin >> tmp;
		if(a[tmp] != 0)
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}