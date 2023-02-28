#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    // int tmp = people[0];
    // int len = -1;
    // for(int i = people.size()-1 ; i >= 1 ; i--) {
    //     if(tmp + people[i] <= limit) {
    //         len = i+1;
    //         break;
    //     }
    // }
    // if(len == -1) {
    //     return people.size();
    // }
    // answer += people.size()-len;
    int cnt = 0;
    int left = 0;
    int right = people.size()-1;
    while(left < right) {
        if(people[left] + people[right] > limit) {
            right--;
        } else {
            cnt++;
            left++;
            right--;
        }
    }
    answer += cnt;
    answer += people.size() - 2 * cnt;
    return answer;
}