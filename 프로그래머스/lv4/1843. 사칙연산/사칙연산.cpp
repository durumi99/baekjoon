#include <bits/stdc++.h>

#define MAX 203
#define INF 987654321
using namespace std;

int dp[MAX][MAX][2];
vector<string> arr;

int sol(int left, int right, int isMax) {
    int& ret = dp[left][right][isMax];
    if(ret != 0)
        return ret;
    
    if(isMax == 1) {
        ret = -INF;
        for(int i = left ; i <= right ; i++) {
            int leftValue, rightValue;
            leftValue = (left > i - 1) ? stoi(arr[2 * left]) : sol(left, i - 1, 1);
            if(i + 1 > right) {
                rightValue = stoi(arr[2 * right + 2]);
            } else if(arr[2 * i + 1] == "+") {
                rightValue = sol(i + 1, right, 1);
            } else {
                rightValue = sol(i + 1, right, 0);
            }
            
            if(arr[2 * i + 1] == "+") {
                ret = max(leftValue + rightValue, ret);
            } else {
                ret = max(leftValue - rightValue, ret);
            }
        }
    } else {
        ret = INF;
        for(int i = left ; i <= right ; i++) {
            int leftValue, rightValue;
            leftValue = (left > i - 1) ? stoi(arr[2 * left]) : sol(left, i - 1, 0);
            if(i + 1 > right) {
                rightValue = stoi(arr[2 * right + 2]);
            } else if(arr[2 * i + 1] == "+") {
                rightValue = sol(i + 1, right, 0);
            } else {
                rightValue = sol(i + 1, right, 1);
            }
            
            if(arr[2 * i + 1] == "+") {
                ret = min(leftValue + rightValue, ret);
            } else {
                ret = min(leftValue - rightValue, ret);
            }
        }
    }
    
    return ret;
}
int solution(vector<string> _arr)
{
    
    int answer = -1;
    arr = _arr;
    
    return sol(0, arr.size() / 2 - 1, 1);
}