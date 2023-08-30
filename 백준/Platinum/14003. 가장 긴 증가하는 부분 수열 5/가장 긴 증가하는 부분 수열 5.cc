#include <iostream>
#include <bits/stdc++.h>

#define MAX 1000001
using namespace std;
int n;
vector <int> a, lis;
int main() {
    int idx[MAX];
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
        
    }
    for(int i = 0 ; i < n ; i++) {
        if(lis.size() == 0 || lis[lis.size() - 1] < a[i]) {
            lis.push_back(a[i]);
            idx[i] = lis.size() - 1;
        }
        else {
            int pos = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            
            lis[pos] = a[i];
            idx[i] = pos;
        }
        
        // for(int i = 0 ; i < lis.size() ; i++)
        //     cout << lis[i] << ' ';
        // cout << '\n';
    }
    cout << lis.size() << '\n';
    vector<int> answer;
    int findIdx = lis.size() - 1;
    for (int i = n - 1 ; i >= 0; i--)
    {
        if (idx[i] == findIdx)
        {
            findIdx--;
            answer.push_back(a[i]);
        }
    }
    for (int i = answer.size() - 1; i >= 0; i--) 
        cout << answer[i] << " ";
    cout << '\n';
    return 0;
}