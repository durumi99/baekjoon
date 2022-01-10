#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
int Index[111111];
int in[111111];
int post[111111];

void f(int inStart, int inEnd,int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd)
        return;
    int rootIndex = Index[post[postEnd]]; // Inorder 에서 root의 Index 
    int leftSize = rootIndex - inStart;
    cout << in[rootIndex] << ' ';
    
    f(inStart,rootIndex-1,postStart, postStart + leftSize - 1);
    f(rootIndex + 1 , inEnd, postStart + leftSize, postEnd -1);
}
void input(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> in[i];
        Index[in[i]] = i;
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> post[i];
    }  
}
int main() {
    input();
    f(1,n,1,n);
    
    return 0;
}