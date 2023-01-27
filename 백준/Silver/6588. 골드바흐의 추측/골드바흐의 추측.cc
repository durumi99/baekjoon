#include <iostream>
#include <cmath>

using namespace std;

int primeNum[1000001];

void setPrimeNum() {
	for(int i = 2 ; i <= 1000000 ; i++) {
		primeNum[i] = i;
	}
	
	for(int i = 2 ; i <= sqrt(1000000) ; i++){
		if(primeNum[i] == 0)
			continue;
			
		for(int j = i * i ; j <= 1000000 ; j += i)
			primeNum[j] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
 
	// your code goes here
	setPrimeNum();
	while(true){
		int n; cin >> n;
		if(n == 0)
			break;
		int tmp = 3;	
		while(tmp < n/2 + 1) {
			if(primeNum[tmp] && primeNum[n-tmp])
				break;
			tmp += 2;
		}
		if(tmp > n/2 + 1) {
			cout << "Goldbach's conjecture is wrong.\n";
		} else {
			cout << n << " = " << tmp << " + " << n-tmp << '\n';
		}
	}
	return 0;
}