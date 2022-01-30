#include <iostream>
#include <algorithm>

#define MAX 101010
#define INF 2e9
using namespace std;
int n;
int arr[MAX];

void f(){
    int start = 0, end = n-1;
    int answer1 = 0,answer2 = n-1;
    int sum = INF;
    while(start < end){
        if(arr[start] + arr[end] == 0){ // 합이 0 이면 바로 답 출력
            answer1 = start;
            answer2 = end;
            break;
        }
        if(abs(arr[start] + arr[end]) < sum){
            sum = abs(arr[start] + arr[end]);
            answer1 = start;
            answer2 = end;
        }
        if( arr[start] + arr[end] < 0){
            start++;
        }
        else{
            end--;
        }
    }
    cout << arr[answer1] << ' ' << arr[answer2];
}
int main() {
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >>arr[i];
    f();
    return 0;
}