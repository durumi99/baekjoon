#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
 
class change{
private:
    string str;
    int len;
    string str1[8] = {"0", "1", "10", "11", "110", "101", "110", "111"};
    string str2[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
public:
    void setStr(){
        cin >> str;
        len = static_cast<int>(str.size());
    }
    void callSolution(){
        this->printFirstNum(str[0]-'0');     //8진수 맨 처음 수
 
        for(int i=1; i<len ;i++){
            this->printNum(str[i]-'0');
        }
    }
    void printFirstNum(int num) const{
        cout << str1[num];
    }
    void printNum(int num) const{
        cout << str2[num];
    }
};
 
int main(void){
    change oct;
    oct.setStr();
    oct.callSolution();
    return 0;
}