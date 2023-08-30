#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> a, lis;
int main() {
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
        
    }
    for(int i = 0 ; i < n ; i++) {
        if(lis.size() == 0 || lis[lis.size() - 1] < a[i])
            lis.push_back(a[i]);
        else {
            int left = 0;
            int right = lis.size();
            while(left < right) {
                int mid = (left + right) / 2;
                if (lis[mid] >= a[i])
                    right = mid;
                else
                    left = mid + 1;
            }
            lis[left] = a[i];
        }
    }
    cout << lis.size() << '\n';
    // for(int i = 0 ; i < lis.size() ; i++)
    //     cout << lis[i] << ' ';
    return 0;
}