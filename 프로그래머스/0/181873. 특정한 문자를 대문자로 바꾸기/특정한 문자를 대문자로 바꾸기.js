function solution(my_string, alp) {
    var answer = [...my_string].map((el) => {
        if(el === alp) {
            return el.toUpperCase();
        }
        
        return el;
    }).join('');
    return answer;
}