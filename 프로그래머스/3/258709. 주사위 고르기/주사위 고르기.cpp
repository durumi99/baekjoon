#include <bits/stdc++.h>
#define diceEyes 6

using namespace std;
vector<vector<int>> dice;
vector <int> A;
vector <int> B;
int maxWinCnt = 0;

int calWinCnt() {
    int cnt = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(auto aEl : A) {
        auto lower = lower_bound(B.begin(), B.end(), aEl);
        cnt += lower - B.begin();
    }
    
    return cnt;
}

void calSum(vector <vector<int>> selectedDices, int curSum, int index, int flag) { // 0 : A, 1 : B
    if(index == selectedDices.size()) {
        if (flag == 0) {
            A.push_back(curSum);
        } else {
            B.push_back(curSum); 
        }
        return;
    }
    for(int i = 0 ; i < diceEyes ; i++) {
        calSum(selectedDices, curSum + selectedDices[index][i], index + 1, flag);
    }
}
vector<int> solution(vector<vector<int>> _dice) {
    dice = _dice;
    vector<int> answer(_dice.size() / 2);
    vector<int> tmp;
    for(int i = 1 ; i >= 0 ; i--) {
        for(int j = 0 ; j < dice.size() / 2; j++) {
            tmp.push_back(i);
        }
    }
    
    do {
        A.clear();
        B.clear();
        vector <vector<int>> selectedByA;
        vector <vector<int>> selectedByB;
        vector <int> selectedByAIdx;
        vector <int> selectedByBIdx;
        
        for (int i = 0 ; i < dice.size() ; i++) {
            if(tmp[i] == 1) { // A가 선택한 주사위
                selectedByA.push_back(dice[i]);
                selectedByAIdx.push_back(i + 1);
            } else { // B가 선택한 주사위
                selectedByB.push_back(dice[i]);
                selectedByBIdx.push_back(i + 1);
                
            }
        }
        calSum(selectedByA, 0, 0, 0);
        calSum(selectedByB, 0, 0, 1);
        
        // cout << A.size() << '\n';
        // cout << B.size() << '\n';
        int winCnt = calWinCnt();
        for(auto el : selectedByAIdx) {
            cout << el << ' ';
        }
        cout << ' ';
        cout << winCnt << '\n';
        if(winCnt > maxWinCnt) {
            maxWinCnt = winCnt;
            for(int i = 0 ; i < selectedByAIdx.size() ; i++) {
                answer[i] = selectedByAIdx[i];
            }
        }
        
    } while(prev_permutation(tmp.begin(), tmp.end()));
    
    return answer;
}