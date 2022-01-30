#include <iostream>
#include <vector>
#define MAX 4000001
using namespace std;
vector <int> v;
int dp[MAX];
void makePrime(){
    bool primeArr[MAX];
    for(int i =2 ; i <= MAX ; i++)
        primeArr[i] = true;
        
    for(int i = 2; i * i <= MAX ; i++){
        if(primeArr[i])
            for(int j = i * i ; j <= MAX ; j+= i)
                primeArr[j] = false;
    }
    for(int i = 2 ; i <= MAX ; i++){
        if(primeArr[i])
            v.push_back(i);
    }
}
int f(int n){
    int start = 0;
    int end = 0;
    int sum = 0;
    int res = 0;
    while(start <= end){
        if(sum >= n){
            if(sum == n){
                res++;
            }
            sum -=v[start++];
        }
        else if(end == v.size()){
            break;
        }
        else
            sum += v[end++];
    }
    return res;
}
int main() {
    makePrime();
    int n; cin >> n;
    cout << f(n) << '\n';
    return 0;
}