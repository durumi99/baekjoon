#include <iostream>

using namespace std;
int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++){
        int size;
        long long sum = 0;
        cin >> size;
        long long ary[size];
        for(int j = 0 ; j < size ; j++)
            cin >> ary[j];
        for(int i = 0 ; i < size; i++)
    		for(int j = i+1; j < size; j++)
        		sum += gcd(ary[i],ary[j]);
        cout << sum << '\n';
    }
    return 0;
}