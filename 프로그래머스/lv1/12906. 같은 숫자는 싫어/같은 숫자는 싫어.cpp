#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    stack <int> s;
    for(int i = 0 ; i < arr.size() ; i++) {
        if(!s.empty() && s.top() == arr[i]) {
            continue;
        }
        answer.push_back(arr[i]);
        s.push(arr[i]);
    }

    return answer;
}