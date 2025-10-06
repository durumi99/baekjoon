function solution(phone_number) {
    var answer = '';
    const len = phone_number.length;
    
    answer = phone_number.split('').map((el, idx) => {
        if(idx < len - 4) {
            return '*';
        }
        
        return el;
    })
    
    return answer.join('');
}