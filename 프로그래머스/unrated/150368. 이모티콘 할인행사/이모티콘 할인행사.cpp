#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


vector<int> answer;
vector<vector<int>> users;
vector<int> emoticons;
vector<int> discountRates;
int n, m;
int arr[4] = {10, 20, 30, 40};
int EPS = 0;
int maxProfit = 0;

void dfs() {
    if(discountRates.size() == m){
        
        int eps = 0;
        int totalPrice = 0;
        for(auto user : users) {
            int userRate = user[0];
            int userLimit = user[1];
            int sum = 0;

            for(int i = 0 ; i < m ; i++) {
                if(discountRates[i] >= userRate) {
                    sum += emoticons[i] * (100 - discountRates[i]) / 100;
                } 
            }
            if(sum >= userLimit) {
                eps++;
            } else {
                totalPrice += sum;
            }
        }

        if(eps > EPS) {
            EPS = eps;
            maxProfit = totalPrice;
         } else if(eps == EPS && totalPrice > maxProfit) {
            maxProfit = totalPrice;
        }
        return;
    } 
    
    for(int i = 0 ; i < 4 ; i++) {
        discountRates.push_back(arr[i]);
        dfs();
        discountRates.pop_back();
    }
};

vector<int> solution(vector<vector<int>> _users, vector<int> _emoticons) {
    users = _users;
    emoticons = _emoticons;
    n = _users.size();
    m = _emoticons.size();
    
    dfs();
    
    answer.push_back(EPS);
    answer.push_back(maxProfit);
    return answer;
    
}