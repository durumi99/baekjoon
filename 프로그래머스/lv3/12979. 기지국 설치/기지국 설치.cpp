#include <bits/stdc++.h>

#define MAX 200000022

using namespace std;

// vector <int> arr(MAX);
int solution(int n, vector<int> stations, int w)
{
    int answer = 0, start = 1, index = 0;

    while(start <= n)
    {
        if(start >= stations[index] - w && start <= stations[index] + w)
        {
            start = stations[index] + w;
            index++;
        }
        else
        {
            start += 2 * w;
            answer++;
        }
        start++;
    }
    return answer;
}