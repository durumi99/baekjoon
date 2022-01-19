#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,tmp, answer = 0;
vector <int> party[55];
vector <int> knowTruth; 

void tellTruth(vector <int> v){ // 진실을 아는사람을  업데이트
    for(int i = 0 ; i < v.size(); i++){
        knowTruth.push_back(v[i]);
    }
    sort(knowTruth.begin(), knowTruth.end());
    knowTruth.erase(unique(knowTruth.begin(),knowTruth.end()), knowTruth.end());
}
bool isKnow(vector <int> v){ // party 에 진실이 아는 사람이 있는지 판별
    for(int i = 0 ; i < v.size(); i++){
        for(int j = 0 ; j < knowTruth.size() ; j++){
            if(v[i] == knowTruth[j]){
                return true;
            }
        }
    }
    return false;
}
bool allKnow(vector <int> v){ //파티에 참석하는 사람이 모두 진실을 아는지 판별
    for(int i = 0 ; i < v.size() ; i++){
        if(find(knowTruth.begin(),knowTruth.end(),v[i]) == knowTruth.end())
            return false;
    }
    return true;
}
void disjoint(){
    while(true){
        bool changed = false;
        for(int i = 0 ; i < m ; i++){
            if(isKnow(party[i]) && !allKnow(party[i])){ // 파티에 참가하는 인원 중 일부는 진실을 알고 있음
                changed = true;
                tellTruth(party[i]);
            }
        }
        if(!changed)
            break;
    }
}
void exaParty(){ // 과장되어 말할 수 있는 파티의 수 출력
    for(int i = 0 ; i < m ; i++){
        if(!isKnow(party[i]))
            answer++;
    }
    cout << answer << '\n';
}
void input(){ // 입력받는 함수
    cin >> n >> m;
    int knowCnt; cin >> knowCnt;
    for(int i = 0 ; i < knowCnt; i++){
        cin >> tmp;
        knowTruth.push_back(tmp);
    }
    for(int i = 0 ; i < m ; i++){
        int partyCnt; cin >> partyCnt;
        for(int j = 0 ; j < partyCnt; j++){
            cin >> tmp;
            party[i].push_back(tmp);
        }
    }
}
int main() {
    input();
    disjoint();
    exaParty();
    return 0;
}