#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for(int i = 0 ; i < n ; i++){
        int tmp1 = arr1[i], tmp2 = arr2[i];
        vector <int> map1(n), map2(n);
        
        int cur = n - 1;
        while(tmp1){
            map1[cur--] = tmp1 % 2;
            tmp1 /= 2;
        }
        cur = n - 1;
        while(tmp2){
            map2[cur--] = tmp2 % 2;
            tmp2 /= 2;
        }
        
        for(int j = 0 ; j < n ; j++){
            if(map1[j] | map2[j])
                answer[i].append("#");
            else
                answer[i].append(" ");
        }
    }
    return answer;
}