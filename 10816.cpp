#include <iostream>
#include <algorithm>
using namespace std;
int lower_binary(int*arr,int target,int size) {
    int mid, start, end;
    start = 0, end = size - 1;
 
    while (end > start){
        mid = (start + end) / 2;
        if (arr[mid] >= target)
            end = mid;
        else start = mid + 1;
    }
    return end;
}
int upper_binary(int*arr, int target,int size) {
    int mid, start, end;
    start = 0, end = size - 1;
 
    while (end > start) {
        mid = (start + end) / 2;
        if (arr[mid] > target)
            end = mid;
        else start = mid + 1;
    }
    return end;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,tmp,m;
	cin >> n;
	int input[n] = {0,};
	for(int i = 0 ; i < n ; i++){
		cin >> input[i];
	}
	sort(input,input+n);
	
	cin >> m;
	for(int i = 0 ; i < m ; i++){
		cin >> tmp;
		int upper = upper_binary(input,tmp,n);
		int lower = lower_binary(input,tmp,n);
		if ( upper == n -1 && input[n-1] == tmp)
			upper++;
		cout << upper-lower << ' ';
	}
	return 0;
}