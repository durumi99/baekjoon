#include <iostream>
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n;
int nums[101];
int sol[501];

int main() {
    cin >> n;
    
    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    int incM = nums[1] - nums[0];
    
    for(int i = 2 ; i < n ; i++) {
        incM = gcd(incM, nums[i] - nums[i - 1]);
    }
    
    
    set <int> answers;
    for(int i = 1 ; i * i <= incM ; i++) {
        if(incM % i == 0) {
            answers.insert(i);
            answers.insert(incM / i);
        }
    }
    
    for(auto ans : answers) {
        if(ans != 1)
            cout << ans << ' ';
    }
    return 0;
}