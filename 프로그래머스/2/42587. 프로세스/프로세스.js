function solution(priorities, location) {
    var answer = 1;
    
    const q = priorities.map((priority, idx) => {
       return [idx, priority,];
    })

    
    while(q.length > 0) {
        const [idx, priority] = q.shift();
        const maxPriority = Math.max(...q.map(([idx, priority]) => priority));
        
        if(maxPriority <= priority) {
            if(idx === location) {
                break;
            }
            answer++;
        } else {
            q.push([idx, priority]);
        }
        
    }
    return answer;
}