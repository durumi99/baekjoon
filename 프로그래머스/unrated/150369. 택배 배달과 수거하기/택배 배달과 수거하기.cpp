#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    // 최대치로 들고 배송 다 함
    int remainD = -1,remainP = -1;
    int idx = n - 1;
    while(idx >= 0){
        if(remainD == -1 && deliveries[idx] > 0)
            remainD = idx;
        if(remainP == -1 && pickups[idx] > 0) 
            remainP = idx;
        if(remainD != -1 && remainP != -1)
            break;
        idx--;
    }
    
    while(remainD != -1 || remainP != -1) {
        answer += (max(remainD, remainP) + 1) * 2;
        
        int curCap = 0;
        while(remainD > -1) {
            if(curCap + deliveries[remainD] <= cap) {
                curCap += deliveries[remainD];
                deliveries[remainD] = 0;
            } else if(curCap == cap) {
                break;
            } else {
                deliveries[remainD] -= cap - curCap;
                curCap = cap;
                break;
            }
            remainD--;
        }
        curCap = 0;
        while(remainP > -1) {
            if(curCap + pickups[remainP] <= cap) {
                curCap += pickups[remainP];
                pickups[remainP] = 0;
            } else if(curCap == cap) {
                break;
            } else {
                pickups[remainP] -= cap - curCap;
                curCap = cap;
                break;
            }
            remainP--;
        }
    }
    return answer;
}

// #include <string>
// #include <vector>
// #include <bits/stdc++.h>

// using namespace std;

// long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
//     long long answer = 0;

//     int del = 0;
//     int pic = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (deliveries[i] != 0 || pickups[i] != 0)
//         {
//             int cnt = 0;
//             while (del < deliveries[i] || pic < pickups[i])
//             {
//                 ++cnt;
//                 del += cap;
//                 pic += cap;
//             }
//             cout << del << ' ' << pic << '\n';
//             del -= deliveries[i];
//             pic -= pickups[i];
//             answer += (1LL * cnt) * (1LL * (i + 1)) * 2;
//             cout << del << ' ' << pic << '\n';
//         }
//     }

//     return answer;
// }