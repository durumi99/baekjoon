function solution(targets) {
    var answer = 0;
    let curLoc = 0;
    targets.sort((a, b) => a[1] - b[1]);
    
    targets.forEach((target) => {
        if(target[0] < curLoc) 
            return;
        answer++;
        curLoc = target[1];
    })
    return answer;
}