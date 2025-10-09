function solution(my_strings, parts) {
    var answer = my_strings.reduce((acc, el, idx) => {
        const [start, end] = parts[idx];
        acc += el.slice(start, end + 1);
        
        return acc;
    }, '');
    return answer;
}