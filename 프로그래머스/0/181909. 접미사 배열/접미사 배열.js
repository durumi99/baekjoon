function solution(my_string) {
    var answer = [...new Set([...my_string].reduce((acc, el, idx) => {
        acc.push(my_string.substr(idx));
        
        return acc;
    }, []))].sort();
    return answer;
}