function solution(my_string) {
    var answer = [...my_string].map((el) => {
        if(el.toUpperCase() === el) {
            return el.toLowerCase();
        }
        
        return el.toUpperCase();
    }).join('');
    return answer;
}