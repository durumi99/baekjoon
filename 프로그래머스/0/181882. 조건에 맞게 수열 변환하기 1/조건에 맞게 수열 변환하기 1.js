function solution(arr) {
    var answer = arr.map((el) => {
        if(el >= 50 && el % 2 === 0) {
            return el / 2;
        } else if(el < 50 && el % 2) {
            return el * 2;
        } else {
            return el;
        }
    });
    
    return answer;
}