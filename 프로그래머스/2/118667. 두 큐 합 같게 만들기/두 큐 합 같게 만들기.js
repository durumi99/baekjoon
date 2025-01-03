function solution(queue1, queue2) {
    var answer = -2;
    const queue = queue1.concat(queue2);
    
    const sum = queue.reduce((acc, cur) => {
      return acc + cur;
    }, 0) / 2;  
    
    let curSum = queue1.reduce((acc, cur) => {
      return acc + cur;
    }, 0);
    
    let left = 0;
    let right = queue1.length;
    let cnt = 0;
    
    while(curSum !== sum && cnt < queue.length * 2) {
        if (curSum > sum) {
            curSum -= queue[left];
            left = (left + 1) % queue.length;
        } else if (curSum < sum) {
            curSum += queue[right];
            right = (right + 1) % queue.length;
        }
        cnt++;
    }
    
    if(cnt == queue.length * 2) {
        return -1;
    }
    
    return cnt;
}