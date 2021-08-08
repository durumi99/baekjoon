#include <iostream>
#include <vector>
using namespace std;

vector <int> dp;
int main() {
    int N ; cin >> N;
    for(int i = 1 ; i <= N ; i++){
        int a ; cin >> a;
        if(dp.empty() || dp.back() < a){
             dp.push_back(a);
        }
        else{
            auto it = lower_bound(dp.begin(),dp.end(),a);
            *it = a;
        }
    }
    cout << N - dp.size() << '\n';
    return 0;
}