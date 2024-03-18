#include<bits/stdc++.h>

using namespace std;
vector <vector<int>> vertices(1000000);
vector <int> inVertexCnt(1000000);
vector <int> answer;
int graphCnt[3] = {0, }; // 0 : donut, 1 : stick, 2: eight;
vector <int> visited(1000000);

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
    int len = edges.size();
    int startVertex;
    
    // visited.resize(len + 1);
    // vertices.resize(len + 1);
    
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