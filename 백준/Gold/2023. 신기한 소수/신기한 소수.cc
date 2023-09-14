#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n; 

bool isPrime(int num) {
    if(num == 1)
        return false;
    for(int i = 2 ; i * i <= num ; i++) {
        if(num % i == 0)
            return false;
    }
    
    return true;
}

void bt(int num) {
    if(to_string(num).length() == n) {
        cout << num << '\n';
        return;
    }
    
    for(int i = 1 ; i <= 9 ; i++) {
        if(isPrime(num * 10 + i)) {
            bt(num * 10 + i);
        }
    }
}
int main() {
    cin >> n;
    if(n == 1) {
        cout << 2 << '\n';
        cout << 3 << '\n';
        cout << 5 << '\n';
        cout << 7 << '\n';
    } else {
        bt(0);
    }
    return 0;
}