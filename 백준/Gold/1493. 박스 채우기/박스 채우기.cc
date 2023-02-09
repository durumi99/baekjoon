#include <iostream>
#include <cmath>

#define MAX 1e18+1
using namespace std;

int l, w, h;
int n;
int cube[22];
int ans = MAX;

int dq(int l, int w, int h, int idx) {
    //  cout << l << ' ' << w << ' ' << h << ' ' << idx << ' ' << cube[idx] << '\n';
    if(l == 0 || w == 0 || h == 0){
        return 0;
    }
    if(idx < 0) {
        return -1;
    }
    int tmp = pow(2, idx);
    // 넣을 수 있는 가장 큰 큐브를 넣었을 떄
   
    if(cube[idx] && l >= tmp && w >= tmp && h >= tmp) {
        cube[idx]--;
        int dq1 = dq(l, w, h-tmp, idx);
        int dq2 = dq(l-tmp, w, tmp, idx);
        int dq3 = dq(tmp, w-tmp, tmp, idx);
        
        if(dq1 == -1 || dq2 == -1 || dq3 == -1)
            return -1;
        return dq1 + dq2 + dq3 + 1;
    }
    // 안 넣었을 때
    return dq(l, w, h, idx-1);
}
int main() {
    cin >> l >> w >> h;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        int tmp;
        cin >> tmp;
        cin >> cube[tmp];
    }
    
    ans = dq(l, w, h, 20);
    
    cout << ans << '\n';
    return 0;
}