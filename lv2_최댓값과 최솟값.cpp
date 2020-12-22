#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
bool cmp(string a, string b)
{
    int numA = stoi(a);
    int numB = stoi(b);
    
    if(numA <= numB)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
string solution(string s) 
{
    vector<string> v;
    string temp = "";
    string answer = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            v.push_back(temp);
            temp = "";
            continue;
        }
        else
        {
            temp += s[i];        
        }
    }
    v.push_back(temp);
    
    sort(v.begin(), v.end(), cmp);
 
    answer += v[0];
    answer += " ";
    answer += v[v.size()-1];
    
    return answer;
}