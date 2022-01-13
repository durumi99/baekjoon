#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack <char> s;
string input;

void post(){
    for(int i = 0; i < input.size(); i++){
        if(input[i] >= 'A' && input[i] <= 'Z')
            cout << input[i];
        else if(input[i] == '('){
            s.push(input[i]);
        }
        else if(input[i] == ')'){
            while(s.top() != '(' && !s.empty()){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if(input[i] == '/' || input[i] == '*'){
            while(!s.empty() && ( s.top() == '*' || s.top() == '/' ) ){
                cout << s.top();
                s.pop();
            }
            s.push(input[i]);
        }
        else if(input[i] == '+' || input[i] == '-' ){
            while(!s.empty() && s.top() != '(' ){
                cout << s.top();
                s.pop();
            }
            s.push(input[i]);
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}
int main() {
    cin >> input;
    post();
    return 0;
}