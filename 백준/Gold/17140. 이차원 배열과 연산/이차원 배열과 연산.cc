#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int r, c, k;
int curR, curC;
int A[100][100];

void operR() {
    for(int i = 0 ; i < curR ; i++) {
        int numCnt[101] = {0, };
        for(int j = 0 ; j < curC ; j++) {
            if(A[i][j])
                numCnt[A[i][j]]++;
        }
        vector < pair <int, int> > v;
        for(int j = 1 ; j <= 100 ; j++) {
            if(numCnt[j]) {
                v.push_back({numCnt[j], j});
                if(v.size() == 50)
                    break;
            }
        }
        sort(v.begin(), v.end());
        
        for(int j = 0 ; j < 100 ; j++) {
            A[i][j] = 0;
        }
        int vSize = v.size();
        curC = max(curC, vSize * 2);
        for(int j = 0 ; j < vSize ; j++) {
            A[i][j * 2] = v[j].second;
            A[i][j * 2 + 1] = v[j].first;
        }
    }
}

void operC() {
    for(int i = 0 ; i < curC ; i++) {
        int numCnt[101] = {0, };
        for(int j = 0 ; j < curR ; j++) {
            if(A[j][i])
                numCnt[A[j][i]]++;
        }
        vector < pair <int, int> > v;
        for(int j = 1 ; j <= 100 ; j++) {
            if(numCnt[j]) {
                v.push_back({numCnt[j], j});
                if(v.size() == 50)
                    break;
            }
        }
        sort(v.begin(), v.end());
        for(int j = 0 ; j < 100 ; j++) {
            A[j][i] = 0;
        }
        int vSize = v.size();
        curR = max(curR, vSize * 2);
        
        for(int j = 0 ; j < vSize ; j ++) {
            A[j * 2][i] = v[j].second;
            A[j * 2 + 1][i] = v[j].first;
        }
        
    }
}
int main() {
    cin >> r >> c >> k;
    for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            cin >> A[i][j];
        }
    }
    int ans = -1;
    int cnt = 0;
    curR = 3, curC = 3;
    while(cnt <= 100) {
        if(A[r - 1][c - 1] == k) {
            ans = cnt;
            break;
        }
        if(curR >= curC) { // R연산
            operR();
        } else {
            operC();
        }
        cnt++;
        
        // for(int i = 0 ; i < curR ; i++) {
        //     for(int j = 0 ; j < curC ; j++) {
        //         cout << A[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
//   for(int i = 0 ; i < curR ; i++) {
//         for(int j = 0 ; j < curC ; j++) {
//             cout << A[i][j] << '\t';
//         }
//         cout << '\n';
//     }
//     cout << '\n';
    cout << ans;
    return 0;
}