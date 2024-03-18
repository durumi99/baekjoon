#include<bits/stdc++.h>

using namespace std;
vector <vector<int>> vertices;
vector <int> inVertexCnt;
vector <int> visited;

vector <int> answer;
int graphCnt[3] = {0, }; // 0 : donut, 1 : stick, 2: eight;


void dfs(int currentVertex) {
    if(vertices[currentVertex].size() == 0) { // 연결된 다음 정점이 없는 경우
        graphCnt[1]++; // stick
    } else if (vertices[currentVertex].size() == 2) { // 연결된 다음 정점이 2개인 경우
        graphCnt[2]++; // eight
    } else {
        for(auto vertex : vertices[currentVertex]) {
            if(visited[vertex] != 1) {
                visited[vertex] = 1;
                dfs(vertex);
            }
        }
        return;
    }
    
    return;
}
vector<int> solution(vector<vector<int>> edges) {
    int len = 0;
    int startVertex;
    
    for(auto edge : edges) {
        int a = edge[0];
        int b = edge[1];
        len = max(a, len);
        len = max(b, len);
    }
    len++;
    
    visited.resize(len);
    vertices.resize(len);
    inVertexCnt.resize(len);
    
    
    for(auto edge : edges) {
        int a = edge[0];
        int b = edge[1];
        vertices[a].push_back(b);
        inVertexCnt[b]++;
    }
    
    for(int i = 1 ; i < len + 1 ; i++) {
        if(vertices[i].size() >= 2 && inVertexCnt[i] == 0) {
            startVertex = i;
            break;
        }
    }
    
    answer.push_back(startVertex);
    for (auto vertex : vertices[startVertex]) {
        visited[vertex] = 1;
        dfs(vertex);
    }
    
    graphCnt[0] = vertices[startVertex].size() - graphCnt[1] - graphCnt[2];
    
    for(int i = 0 ; i < 3 ; i++) {
        answer.push_back(graphCnt[i]);
    }
    return answer;
}
