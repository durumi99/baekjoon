#include <bits/stdc++.h>

#define pii pair <int, int>
#define MAX 100001
using namespace std;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

set < pii > node;
set < pair <pii, pii> > edge;
int solution(vector<int> arrows) {
    int answer = 0;
    int y = 0, x = 0;
    node.insert({y, x});
    
    for(auto i : arrows) {         
        for(int j = 1 ; j <= 2 ; j++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(node.find({ny, nx}) != node.end()) {
                if(edge.find({{ny, nx}, {y, x}}) == edge.end() && edge.find({{y, x}, {ny, nx}}) == edge.end())
                    answer++;
            }

            node.insert({ny, nx});
            edge.insert({{ny, nx}, {y, x}});
            edge.insert({{y, x}, {ny, nx}});
            y = ny;
            x = nx;
        }
    } 
    return answer;
}