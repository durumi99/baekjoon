#include <iostream>
#include <bits/stdc++.h>
#define MAX 55
using namespace std;

long long power[MAX];
long long a, b;

long long getOne(long long x) {
	long long ret = x & 1;

	for (int i = MAX - 1; i > 0; i--) {
		if (x & (1LL << i)) {
			ret += power[i - 1] + (x - (1LL << i) + 1);
			x -= 1LL << i;
		}
	}

	return ret;
}

int main() {
    
    cin >> a >> b;
    
    power[0] = 1;
    for(int i = 1 ; i < MAX ; i++) {
        power[i] = 2 * power[i - 1] + (1LL << i);
    }
    cout << getOne(b) - getOne(a - 1);
    return 0;
}