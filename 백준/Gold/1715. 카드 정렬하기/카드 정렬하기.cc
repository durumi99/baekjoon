#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue <int, vector<int>, greater<int>> pq;
// int card[100001];

int main() {
    cin >> n ;
    for(int i = 0 ; i < n ; i++) {
        int card; cin >> card;
        pq.push(card);
    }
    // sort(card, card + n);
    int ans = 0;
    while(!pq.empty()) {
        int a = pq.top();
        pq.pop();
        if(pq.empty())
            break;
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans;
    return 0;
}