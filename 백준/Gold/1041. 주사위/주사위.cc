#include <iostream>
#include <cmath>
using namespace std;
int n;
int dice[6];
int a, b, c, d, e, f;

int minThreeSum;
int minTwoSum = 100;
int minEye = 50;
int maxEye = -1;
int sum = 0;

void getMin() {
    dice[0] = a;
    dice[1] = b;
    dice[2] = c;
    dice[3] = d;
    dice[4] = e;
    dice[5] = f;
    
    int tmp1 = min(a, f);
    int tmp2 = min(min(b+c,c+e) , min(b+d, d+e));
    minThreeSum = tmp1 + tmp2;

    for(int i = 0 ; i < 6 ; i++) {
        sum += dice[i];
        minEye = min(minEye, dice[i]);
        maxEye = max(maxEye, dice[i]);

        for(int j = 0 ; j < 6 ; j++) {
            if(i == j)
                continue;
            if( (i == 0 && j == 5) || (i == 5 && j == 0) )
                continue;
            if((i == 1 && j == 4) || (i == 4 && j == 1) )
                continue;
            if((i == 2 && j == 3) || (i == 3 && j == 2))
                continue;
            minTwoSum = min(minTwoSum, dice[i] + dice[j]);    
        }
    }
}
int main() {
    cin >> n;
    cin >> a >> b >> c >> d >> e >> f;
    getMin();
    if(n == 1) {
        cout << sum - maxEye;
        return 0;
    }

    unsigned long long surfaceCnt = pow(n, 2) * 5;
    long long ans = 0;
    
    ans += 4 * minThreeSum;
    surfaceCnt -= 12;
    
    ans += 4 * (2*n-3) * minTwoSum;
    surfaceCnt -= 4 * (2*n-3) * 2;
    
    ans += surfaceCnt * minEye;
    
    cout << ans;
    return 0;
}