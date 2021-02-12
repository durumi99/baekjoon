#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	int tc;
	cin >> tc;
	for(int i = 0 ; i < tc ;i++){
		string func,arr,tmp;
		int n;
		cin >> func >> n >> arr;
		deque <int> dq;
		for(int i = 0 ; i < arr.length(); i++){
			if(arr[i] == '[')
				continue;
			else if( '0' <= arr[i] && arr[i] <= '9')
				tmp += arr[i];
			else if(arr[i] == ',' || arr[i] == ']'){
				if(!tmp.empty()){
					dq.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}
		
		bool error = false;
		bool reverse = false;
		for(int i = 0 ; i < func.length();i++){
			if(func[i] == 'R'){
				reverse = !reverse;
			}
			else{
				if(dq.empty()){
					error = true;
					cout << "error\n";
					break;
				}
				else
					if(reverse)
						dq.pop_back();
					else
						dq.pop_front();
			}
		}
		if(!error){
			cout << '[';
			if(reverse){
				while(!dq.empty()){
					cout <<dq.back();
					dq.pop_back();
					if(!dq.empty())
						cout << ",";
				}
			}
			else {
					while(!dq.empty()){
					cout <<dq.front();
					dq.pop_front();
					if(!dq.empty())
						cout << ",";
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}{\rtf1}