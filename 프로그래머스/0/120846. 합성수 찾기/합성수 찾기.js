function solution(n) {
    var answer = Array.from({length : n }, (_, idx) => idx + 1).reduce((acc, el) => {
        let cnt = 0;
        for(let i = 1 ; i <= el ; i++) {
            if(el % i === 0){
                cnt++;
            }
        }
        if(cnt >= 3) {
            acc++;
        }
        return acc;
    }, 0);
    return answer;
}