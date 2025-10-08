function solution(rsp) {
    var answer = [...rsp].map((el) => {
        if(el === '2') {
            return '0';
        } else if(el === '0') {
            return '5';
        }
        
        return '2';
    }).join('');
    
    return answer;
}