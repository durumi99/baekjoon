function solution(n, k, enemy) {
    var answer = 0;
    let left = 0;
    let right = enemy.length;
    
    while(left <= right) {
        const mid = ~~((left + right) / 2);
        const res = check(enemy.slice(0, mid), n, k);
        
        if (mid === 0) {
            left = mid + 1;
            continue;
        }
        
        if(res) {
            answer = mid; 
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}

function check(subEnemy, n, k) {    
    if (subEnemy.length <= k) {
        return true;
    }
    
    const tmp = subEnemy.sort((a, b) => a - b).slice(0, subEnemy.length - k).reduce((acc, el) => acc + el, 0);
    
    return n >= tmp;
}