#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r; cin >> r;
    const double pi = acos(-1);
    cout << fixed;
    cout.precision(6);
    cout << r * r * pi << '\n';
    cout << r * r * 2;
    return 0;
}