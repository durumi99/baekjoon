#include <bits/stdc++.h>

#define MAX 202
using namespace std;

int root[MAX];

int find(int x) {
    if(root[x] == x)
        return x;
    
    return root[x] = find(root[x]);
}

void unionF(int x, int y) {
    x = find(x);
    y = find(y);
    
    if(x == y)
        return;
    
    root[max(x, y)] = root[min(x, y)];
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0 ; i < n ; i++)
        root[i] = i;
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(computers[i][j] && i != j) {
                unionF(i, j);
            }
        }
    }
    set <int> s;
    for(int i = 0 ; i < n ; i++){
        s.insert(find(i));
    }
    
    answer = s.size();
    return answer;
}