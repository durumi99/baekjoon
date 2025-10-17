function solution(my_str, n) {
    var answer = [...my_str].reduce((acc, el, idx) => {
        if(idx % n === 0) {
            acc.push(my_str.slice(idx, idx + n));
        }
        return acc;
    }, []);
    return answer;
}