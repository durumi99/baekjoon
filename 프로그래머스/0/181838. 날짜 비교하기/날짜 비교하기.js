function solution(date1, date2) {
    var answer = 0;
    let idx = 0;
    
    while(idx < 3) {
        const d1 = date1[idx];
        const d2 = date2[idx];
                
        if(d1 === d2) {
            idx++;
            continue;
        } 
        
        answer = d2 > d1 ? 1 : 0;
        break;
    }
    
    return answer; 
}