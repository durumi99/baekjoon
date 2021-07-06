#include <iostream>

using namespace std;
const long long MN = 10000001;
bool sieve[MN];

int main() {
    
	sieve[0] = true; sieve[1] = true;
    for (int i = 2; i * i < MN; i++) {
        if (sieve[i]) 
            continue;
        for (int p = i * i; p < MN; p += i)
            sieve[p] = true;
    }
    
    long long a,b;
    cin >> a >> b;
    int cnt = 0, maxp =100;
    for(long long i = 2 ; i < MN ; i++){
        if(sieve[i])
            continue;
        long long tmp = i * i;
        int p = 2;
        while (p <= maxp && tmp <= b) {
            if (tmp >= a){
                cnt++;
            }
            tmp *= i;
            p++;
        }
        maxp = p - 1;
        if (maxp == 1) break;
    }
    cout << cnt;
	return 0;
}