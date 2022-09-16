#include <string>
#include <vector>
#include <queue>
using namespace std;

void popAndInsert(queue <int> &popQueue, queue <int> &insertQueue){
    insertQueue.push(popQueue.front());
    popQueue.pop();
}
long getSum(vector<int> queue){
    long tmp = 0;
    for(int i = 0 ; i < queue.size() ; i++)
        tmp += queue[i];
    return tmp;
}
int makeSumSame(vector<int> queue1, vector<int> queue2, long sum){
    queue <int> q1,q2;
    int cnt = 0;
    int res = -1;
    long tmp = getSum(queue1);
    for(int i = 0 ; i < queue1.size() ; i++){
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    int queueSize = q1.size();
    while(cnt < 3 * queueSize){
        if(tmp < sum){
            tmp += q2.front();
            popAndInsert(q2,q1);
        }
        else if(tmp > sum){
            tmp -= q1.front();
            popAndInsert(q1,q2);
        }
        else{
            res = cnt;
            break;
        }
        cnt++;
    }
    return res;
}
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    long sum = 0;
    for(int i = 0 ; i < queue1.size() ; i++){
        sum += queue1[i];
        sum += queue2[i];
    }
    sum /= 2;
    answer = makeSumSame(queue1,queue2,sum);
    return answer;
}