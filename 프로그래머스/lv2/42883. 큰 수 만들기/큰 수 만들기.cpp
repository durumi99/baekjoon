#include <bits/stdc++.h>

using namespace std;
string maxStr = "";
string solution(string number, int k) {
    string answer = "";
    string original = number;
    int kk = k;
    int startIdx = 0;
    
    while(k && startIdx < number.size()) {
        // cout << "number : " << number << ' ' << "k : " << k << ' ';
        int maxIdx = startIdx;
        char maxChar = number[startIdx];
        int minLen = min((int)number.length(), startIdx+k+1);
        
        for(int i = startIdx + 1 ; i < minLen ; i++) {
            if(maxChar < number[i]) {
                maxIdx = i;
                maxChar = number[i];
            }
        }
        // cout << "startIdx : " << startIdx << ' ' << "maxIdx : " << maxIdx << ' ';
        // cout << "maxChar : " << maxChar << '\n';
        if(maxIdx == startIdx){
            startIdx++;
        } else {
            number.erase(startIdx, maxIdx-startIdx);
            k -= (maxIdx-startIdx);
        }       
    }
    
    if(original == number) {
        // cout << number << '\n';
        number.erase(number.size()-kk, kk);
    }
    answer += number;
    return answer;
}