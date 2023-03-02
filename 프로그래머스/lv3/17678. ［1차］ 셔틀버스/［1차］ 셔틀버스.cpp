#include <bits/stdc++.h>

using namespace std;

int lastBus; 
vector <int> timetable;

int ttConvert(string str) {
    int hour = stoi(str.substr(0, 2));
    int min = stoi(str.substr(3));
    // cout << hour << ' ' << min;
    return hour * 60 + min;
}
string ttConvert(int bus) {
    int hour = bus / 60;
    int min = bus % 60;
    string str = "";
    if(hour < 10)
        str += "0";
    str += to_string(hour);
    str += ":";
    if(min < 10)
        str += "0";
    str += to_string(min);
    return str;
}

string solution(int n, int t, int m, vector<string> _timetable) {
    int N = _timetable.size();
    string answer = "";
    lastBus = ttConvert("09:00") + (n-1) * t;
    answer += ttConvert(lastBus);
    for(int i = 0 ; i < N; i++)
        timetable.push_back(ttConvert(_timetable[i]));
    sort(timetable.begin(), timetable.end());
    
    int idx = 0;
    int seat;
    
    for(int i = 0 ; i < n ; i++) {
        int curBus = ttConvert("09:00") + t * i;
        int cnt = 0;
        
        while(idx < N && timetable[idx] <= curBus && cnt < m) {
            cnt++;
            idx++;
        }
        seat = m - cnt;
    }
    cout << idx << ' ' << n * m << ' ' << N << ' ' << seat;
    // idx 이번에
    if(idx >= n * m || seat == 0) { // 못타는 사람이 있는 경우
        answer = min(answer, ttConvert(timetable[idx-1]-1));
    } 
    return answer;
}