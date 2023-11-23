#include <bits/stdc++.h>

using namespace std;

string table[2501] = {"", };
int parent[2501];

vector<string> answer;

int find(int x) {
	if (parent[x] == x) 
        return x;
	return parent[x] = find(parent[x]);
}
void update(int r, int c, string value) {
    int x = find((r - 1) * 50 + c);
    for(int i = 1; i <= 50 * 50; i++) {
        if(find(i) == x)
            table[i] = value;
    }
}

void update(string value1, string value2) {
    for(int i = 1 ; i <= 50 * 50 ; i++) {
        if(table[i] == value1)
            table[i] = value2; 
    }
}

void merge(int r1, int c1, int r2, int c2) {
    if(r1 == r2 && c1 == c2)
        return;
    int x = find((r1 - 1) * 50 + c1);
    int y = find((r2 - 1) * 50 + c2);
    if(x == y)
        return;
	parent[y] = x;
    
    string tmp;
    // if(table[x] == "" && table[y] == "")
    //     tmp = "";
    // else 
    if(table[x] != "EMPTY")
        tmp = table[x];
    else
        tmp = table[y];
    for(int i = 1 ; i <= 50 * 50 ; i++) {
        if(find(i) == x)
            table[i] = tmp;
    }
    
}

void unmerge(int r, int c) {
    int x = find((r - 1) * 50 + c);
    string tmp = table[x];
    
    for(int i = 1 ; i <= 50 * 50 ; i++) {
        find(i);
    }
    for(int i = 1 ; i <= 50 * 50 ; i++) {
        if(find(i) == x) {
            parent[i] = i;
            table[i] = "EMPTY";
        }
    }
    table[(r - 1) * 50 + c] = tmp;
}

void print(int r, int c) {
    int x = find((r - 1) * 50 + c);
    // answer.push_back((table[x] == "") ? "EMPTY" : table[x]);
    answer.push_back(table[x]);
}
void printTable() {
    for(int i = 1 ; i <= 4 ; i++) {
        for(int j = 1 ; j <= 4 ; j++) {
            // cout << i << ' ' << j << ' ' ;
            if(table[(i - 1) * 50 + j] == "")
                cout << "X ";
            else
                cout << table[(i - 1) * 50 + j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

// void printParent(){
//     for(int i = 1 ; i <= 2 ; i++) {
//         for(int j = 1 ; j <= 2 ; j++) {
//             cout << "{" << parent[i][j].first << ' ' << parent[i][j].second << "}" << ' ';
//         }
//         cout << '\n';
//     }
//     cout << '\n';
// }
vector<string> solution(vector<string> commands) {
    for(int i = 1 ; i <= 50 * 50 ; i++) {
        parent[i] = i; 
        table[i] = "EMPTY";
    }
    
    for(auto command : commands) {
        stringstream stream;
        stream.str(command);
        string tmp;
        vector<string> v;
        
        while(stream >> tmp) {
            v.push_back(tmp);
            // cout << tmp << ' ';
        }
        // cout << '\n';
        bool check = true;
        if(v[0] == "UPDATE") {
            check = false;
            if(v.size() == 4) {
                update(stoi(v[1]), stoi(v[2]), v[3]);
            } else {
                update(v[1], v[2]);
            }
        } else if(v[0] == "MERGE") {
            merge(stoi(v[1]), stoi(v[2]), stoi(v[3]), stoi(v[4]));
        } else if(v[0] == "UNMERGE") {
            unmerge(stoi(v[1]), stoi(v[2]));
        } else if(v[0] == "PRINT") {
            print(stoi(v[1]), stoi(v[2]));
        }
        
        // printTable();
        // if(check)
        //     printParent();
    }
    return answer;
}