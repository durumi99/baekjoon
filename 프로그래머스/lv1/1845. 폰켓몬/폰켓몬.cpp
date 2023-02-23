#include <bits/stdc++.h>

using namespace std;

set <int> s;
int solution(vector<int> nums)
{
    int answer = 0;
    for(int num : nums)
        s.insert(num);
    answer = min(nums.size()/2, s.size());
    return answer;
}