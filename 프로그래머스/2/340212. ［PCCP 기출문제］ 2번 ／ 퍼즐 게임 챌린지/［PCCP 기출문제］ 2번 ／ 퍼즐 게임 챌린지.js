const MAX = 1e15;

function f(diffs, times, level, limit) {
    let cnt = 0;
    
    for(let i = 0 ; i < diffs.length ; i++) {
        if(diffs[i] <= level) {
            cnt += times[i];
        } else {
            cnt += (diffs[i] - level) * (times[i - 1] + times[i]) + times[i];
        }
        
        if(cnt > limit) {
            return -1;
        }
    }
    
    return cnt;
}

function solution(diffs, times, limit) {
    var answer = 0;
    let left = 1;
    let right = 100000;
    
    answer = limit;
    while(left <= right) {
        let mid = Math.floor((left + right) / 2);
        const cnt = f(diffs, times, mid, limit);
        
        if(cnt !== -1) {
            right = mid - 1;
            answer = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}