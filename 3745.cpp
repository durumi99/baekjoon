#include <iostream>
#include <algorithm>
using namespace std;

const int MN = 1001010;
const int INF = 1e9;

vector <int> dp;
int main() {
    while(true){
        int N = -1; cin >> N;
        if(N == -1)
            break;
        dp.push_back(-INF);
        for(int i = 0 ; i < N ; i++){
            int a ; cin >> a;
            if(dp.back() < a)
                dp.push_back(a);
            else{
                auto it = lower_bound(dp.begin(),dp.end(),a);
                *it = a;
            }
        }
        cout << dp.size() -1 << '\n';
        dp.clear();
        }
    return 0;
}