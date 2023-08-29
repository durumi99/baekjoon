#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int arr[30];
int inDegree[30];

bool isPossible(string tree) {
    int _inDegree[30];
    for(int i = 0 ; i < 30 ; i++) {
        _inDegree[i] = inDegree[i];
    }
    for(int i = 0 ; i < tree.size() ; i++) {
        int idx = tree[i] - 'A';
        if(_inDegree[idx])
            return false;
        int nextIdx = arr[idx];
        _inDegree[nextIdx] = 0;
    }
    return true;
}
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0 ; i < skill.length() - 1 ; i++) {
        int idx1 = skill[i] - 'A';
        int idx2 = skill[i+1] - 'A';
        arr[idx1] = idx2;
        inDegree[idx2] = 1;
    }
    
    for(auto skill_tree : skill_trees) {
        if(isPossible(skill_tree)){
            answer++;
        }
    }
    return answer;
}