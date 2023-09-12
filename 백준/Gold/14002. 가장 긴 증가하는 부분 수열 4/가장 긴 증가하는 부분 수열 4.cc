#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
int a[1001];

vector <int> lis;

int main() {
    int idx[1001];
    
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
        
    for(int i = 0 ; i < n ; i++) {
        if(lis.size() == 0 || lis[lis.size() - 1] < a[i]) {
            lis.push_back(a[i]);
            idx[i] = lis.size() - 1;
        } else {
            int pos = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[pos] = a[i];
            idx[i] = pos;
        }
    }
    
    cout << lis.size() << '\n';
    
    vector <int> answer;
    int findIdx = lis.size() - 1;
    for(int i = n - 1 ; i >= 0 ; i--) {
        if(idx[i] == findIdx) {
            findIdx--;
            answer.push_back(a[i]);
        }
    }
    for(int i = answer.size() - 1 ; i >= 0 ; i--) {
        cout << answer[i] << ' ';
    }
    return 0;
}