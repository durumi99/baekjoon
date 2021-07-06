#include <iostream>
using namespace std;

int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}

int main() {
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d;
    e = a*d + b*c;
    f = b*d;
    int min = gcd(e,f);
    e /= min;
    f /= min;
    cout << e << ' ' << f;
    return 0;
}