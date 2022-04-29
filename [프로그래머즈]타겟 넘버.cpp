#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int val,int cnt,vector<int> numbers,int target){
    if(cnt == numbers.size()){
        if(val == target)
            answer++;
        return;
    }
    dfs(val+numbers[cnt],cnt+1,numbers,target);
    dfs(val-numbers[cnt],cnt+1,numbers,target);
};

int solution(vector<int> numbers, int target) {
    dfs(0,0,numbers,target);
    return answer;
}