#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int A[2020];
int robot[1010];

int main() {
    int n, k; cin >> n >> k;
    for(int i = 0 ; i < 2 * n ; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    
    while(true) {
        cnt++;
        bool check = false;
        int tmp = A[2 * n - 1];
        for(int i = 2 * n - 1 ; i >= 1 ; i--) {
            A[i] = A[i - 1];
        }
        A[0] = tmp;
        for(int i = n - 1 ; i >= 0 ; i--) {
            robot[i+1] = robot[i];
        }
        robot[0] = 0;
        robot[n-1] = 0;
        for(int i = n - 2 ; i >= 0 ; i--) {
            if(robot[i] == 1 && robot[i+1] == 0 && A[i+1] > 0) {
                robot[i+1] = 1;
                robot[i] = 0;
                A[i+1]--;
            }
        }
        if(A[0] > 0) {
            robot[0] = 1; 
            A[0]--;
        }
        int zeroCnt = 0;
        
        for(int i = 0 ; i < 2 * n ; i++) {
            if(A[i] == 0) {
                zeroCnt++;
                if(zeroCnt >= k) {
                    check = true;
                    break;
                }
            }
        }
        if(check)
            break;
            
    }
    cout << cnt;
    return 0;
}