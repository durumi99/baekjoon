#include <iostream>
#include <string>
using namespace std;


int main() {
	int arr[81]= {0};
	int s1,s2,s3,tmp,max=0;
	cin >> s1 >> s2 >> s3;
	for(int i = 1 ; i <= s1 ; i++){
		for(int j = 1 ; j <= s2 ; j++){
			for(int k = 1 ; k <= s3 ; k++){
				arr[i+j+k]++;
			}
		}	
	}
	for(int i = 1 ; i <= (s1+s2+s3); i++){
		if(arr[i] > max){
			max = arr[i];
			tmp = i;
		}
	}
	cout << tmp << endl;
	return 0;
}