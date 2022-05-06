#include <string>
#include <vector>
#include <cmath>

using namespace std;

string convert(int n,int k){
    vector <char> v;
    while(n){
        v.push_back(n%k+'0');
        n /= k;
    }
    string s = "";
    for(int i = v.size()-1 ; i >= 0 ; i--)
        s += v[i];
    return s;
}
bool isPrime(long long num){
    if(num < 2)
        return false;
    for(long long i = 2 ; i*i <= num ; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string newN = convert(n,k);
    long long tmp = 0;
    for(int i = 0 ; i < newN.length() ; i++){
        if(newN[i] >= '1' && newN[i] <= '9')
            tmp = tmp*10 + (long long)(newN[i]-'0');
        else{
            if(isPrime(tmp))
                answer++;
            tmp = 0;
        }
    }
    if(isPrime(tmp))
        answer++;
    return answer;
}