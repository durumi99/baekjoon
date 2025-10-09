function solution(myString) {
    var answer = [...myString].map((el) => {
        if(el < 'l') {
            return 'l';
        }
        
        return el;
    }).join('');
    
    return answer;
}