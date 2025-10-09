function solution(strArr) {
    var answer = strArr.map((el, idx) => {
       return idx % 2 ? el.toUpperCase() : el.toLowerCase(); 
    });
    return answer;
}