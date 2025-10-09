function solution(arr) {
    var answer = arr.reduce((acc, el) => {
        for(let i = 0 ; i < el ; i++) {
            acc.push(el);
        }
        
        return acc;
    }, []);
    return answer;
}