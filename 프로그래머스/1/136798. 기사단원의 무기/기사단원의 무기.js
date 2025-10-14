function solution(number, limit, power) {
    var answer = 0;
    const attacks = Array(number).fill(0).map((_, idx) => getDivisor(idx + 1));
    answer = attacks.reduce((acc, el) => {
        return acc + ((el <= limit) ? el : power);
    }, 0);
    return answer;
}

function getDivisor(n) {
    let cnt = 0;

    for (let i = 1 ; i * i <= n ; i++) {
        if(n % i) {
            continue;
        }
        if(i * i === n) {
            cnt++;
        } else {
            cnt += 2;
        }
    }
    
    return cnt;
}