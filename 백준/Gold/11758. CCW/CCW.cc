#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ccw(pair<int, int>p1, pair<int, int>p2, pair<int, int>p3) {
    int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1; 
}

int main() {
    pair<int, int> p[3];
    for(int i = 0 ; i < 3 ; i++) {
        int x, y; cin >> x >> y;
        p[i] = {x, y};
    }
    
    cout << ccw(p[0], p[1], p[2]);
    return 0;
}