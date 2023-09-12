#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, l;
int arr[111][111];
int runway[111][111];

int main() {
    cin >> n >> l;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> arr[i][j];
        }
    }
    
    
    int cnt = 0;
    bool check;
    for(int i = 0 ; i < n ; i++) {
        // 가로
        check = true;
        
        memset(runway, 0 , sizeof(runway));
        for(int j = 1 ; j < n ; j++) {
            if(arr[i][j] == arr[i][j - 1])
                continue;
            if(abs(arr[i][j] - arr[i][j - 1]) >= 2) {
                check = false;
                break;
            }
            if(arr[i][j] > arr[i][j - 1]) { // 높아질 때
                if(j < l) {
                    check = false;
                    break;
                }
                for(int k = 1 ; k <= l ; k++) {
                    if(runway[i][j - k]) {
                        check = false;
                        break;
                    }
                    runway[i][j - k] = 1;
                }
                
            } else { // 낮아질 때
                if(j > n - l) {
                    check = false;
                    break;
                }
                for(int k = 0 ; k < l ; k++) {
                    if(runway[i][j + k]) {
                        check = false;
                        break;
                    }
                    runway[i][j + k] = 1;
                }
            }
        }
        if(check) {
            cnt++;
        }
        // 세로
        memset(runway, 0 , sizeof(runway));
        check = true;
        for(int j = 1 ; j < n ; j++) {
            if(arr[j][i] == arr[j - 1][i])
                continue;
            if(abs(arr[j][i] - arr[j-1][i]) >= 2) {
                check = false;
                break;
            }
            if(arr[j][i] > arr[j - 1][i]) { // 높아질 때
                if(j < l) {
                    check = false;
                    break;
                }
                for(int k = 1 ; k <= l ; k++) {
                    if(runway[j - k][i]) {
                        check = false;
                        break;
                    }
                    runway[j - k][i] = 1;
                }
            } else { // 낮아질 때
                if(j > n - l) {
                    check = false;
                    break;
                }
                for(int k = 0 ; k < l ; k++) {
                    if(runway[j + k][i]) {
                        check = false;
                        break;
                    }
                    runway[j + k][i] = 1;
                }
            }
        }
        if(check) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}