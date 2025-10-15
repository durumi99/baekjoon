function solution(emergency) {
    var answer = emergency.map(el => {
        return emergency.reduce((acc, el2) => {
            if(el < el2) {
                acc++;
            }
            
            return acc;
        }, 1);
    });
    return answer; 
}