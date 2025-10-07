function solution(array, height) {
    var answer = 0;
    
    array.forEach((el) => {
        if(el > height) {
            answer++;
        }
    });
    
    return answer;
}