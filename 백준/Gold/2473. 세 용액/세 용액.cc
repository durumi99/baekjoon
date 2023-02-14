#include <iostream>
#include <algorithm>

#define MAX 101010
#define INF 3e9
using namespace std;

int n;
long long arr[MAX];
long long answer[3];
long long sum = INF + 1;

void f(int i){
    int start = i + 1, end = n - 1;
    while(start < end){
        long long value = arr[i] + arr[start]  + arr[end];
        if(abs(value) < sum){
            sum = abs(value);
            answer[0] = arr[i];
            answer[1] = arr[start];
            answer[2] = arr[end];
        }
        if(value < 0)
            start++;
        else
            end--;
    }
}
void input(){
    cin >> n; 
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    sort(arr,arr+n);
}
void solve(){
    for(int i = 0 ; i < n - 2 ; i++)
        f(i);
    for(int i = 0 ; i < 3 ; i++)
        cout << answer[i] << ' ';
}
int main() {
    input();
    solve();
    return 0;
}