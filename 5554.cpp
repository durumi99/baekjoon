#include <iostream>
using namespace std;
 
int main() {
    int a[4],sum;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sum = a[0] + a[1] + a[2] + a[3];
    cout << sum / 60 << '\n' << sum % 60;
    return 0;
}
