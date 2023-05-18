#include <iostream>

using namespace std;

int main() {
    int res = -1;
    int n; cin >> n;
    int maxFive = n / 5;
    
    for(int i = maxFive ; i >= 0 ; i--){
        int tmp = n;
        tmp -= 5 * i;
        if(tmp % 3 == 0){
            res = i + (tmp / 3);
            break;
        }
    }
    cout << res;
    return 0;
}