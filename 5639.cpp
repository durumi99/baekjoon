#include <iostream>

using namespace std;
int tree[1000000][2];

void input(int n,int parent){
    if(n < parent){
        if(tree[parent][0] == 0){
            tree[parent][0] = n;
            return;
        }
        else
            input(n,tree[parent][0]);
    }
    else if(n > parent){
        if(tree[parent][1] == 0){
            tree[parent][1] = n;
            return;
        }
        else
            input(n,tree[parent][1]);
    } 
}
void post(int parent){
    if(tree[parent][0] != 0) 
        post(tree[parent][0]);
    if(tree[parent][1] != 0) 
        post(tree[parent][1]);
    if(parent != -1)
        cout << parent << '\n';
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int n, root = -1;
    while(cin >> n){
        if(cin.eof() == 1)
            break;
        if(root == -1) 
            root = n;
        else
            input(n,root);
    }
    
    post(root);
    return 0;
}