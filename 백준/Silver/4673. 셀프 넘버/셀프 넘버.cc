#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nums[10001];
void d(int num) {
    if(num > 10000)
        return;
    if(nums[num] == 0)
        return;
    nums[num] = 0;
    
    int next = num;
    while(num) {
    	next += (num % 10);
    	num /= 10;
    }
    
    // cout << "num : " << num << " next : " << next << '\n';
    d(next);
}
int main() {
    for(int i = 1 ; i <= 10000 ; i++) {
        nums[i] = 1;
    }
    
    for(int i = 1 ; i <= 10000 ; i++) {
        if(nums[i] == 1) {
        	int cur = i;
            int next = i;
            
            while(cur) {
		    	next += (cur % 10);
		    	cur /= 10;
		    }	
		            
            d(next);
        }
    }
    
    for(int i = 1 ; i <= 10000 ; i++) {
        if(nums[i]) 
            cout << i << '\n';
    }
    return 0;
}