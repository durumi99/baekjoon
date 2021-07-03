#include <iostream>
using namespace std;

int main() {
	int a[300001];
	for(int i = 2 ; i <= 300000; i++) 
        a[i] = i;
    for(int i = 2 ; i*i <= 300000 ; i++){
    	if(a[i] == 0)
    		continue;
    	for(int j = i*i; j <= 300000 ; j += i)
    		a[j] = 0;
    }
    int input;
    while(cin >> input){
        if(input == 0)
            break;
        int cnt = 0;
        for(int i = input+1 ; i <= input *2 ; i++)
            if(a[i] != 0)
                cnt++;
        cout << cnt << '\n';
    }
	return 0;
}