#include <iostream>

int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}

int lcm(int a, int b){
    return a * (b / gcd(a,b));
}
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a,b) << '\n' << lcm(a,b);
    return 0;
}