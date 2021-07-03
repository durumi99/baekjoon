#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tmp = 2;
    while(n != 1){
    	while((n % tmp) == 0 ){
    		n /= tmp;
    		cout << tmp << '\n'; 
    	}
    	tmp++;
    }
    return 0;
}