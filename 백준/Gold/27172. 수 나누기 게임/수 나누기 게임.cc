#include <iostream>
#include <bits/stdc++.h>

#define MAX 1000001
using namespace std;

int n;
int player[101010];
int tmp[MAX];
int result[MAX];

int main() {
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> player[i];
        tmp[player[i]] = 1;
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = player[i] * 2 ; j < MAX ; j += player[i]) {
            if(tmp[j]) {
                result[player[i]]++;
                result[j]--;
            }
        }
    }
    
    for(int i = 0 ; i < n ; i++)
        cout << result[player[i]] << ' ';
    return 0;
}