const MOD = 1234567;
const MAX = 100001
const F = new Array(MAX)
function solution(n) {
    var answer = 0;
    // setFibo(n)
    return setFibo(n);
}

function setFibo(max) {
    F[0] = 0;
    F[1] = 1;
    for(let i = 2 ; i <= max ; i++) {
        F[i] = (F[i - 1] + F[i - 2]) % MOD
    }
    return F[max]
}