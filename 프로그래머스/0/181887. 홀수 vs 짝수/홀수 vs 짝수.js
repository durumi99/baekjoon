function solution(num_list) {
    var answer = Math.max(...(num_list.reduce((acc, el, idx) => {
        acc[idx % 2 ? 1 : 0] += el;
        return acc;
    }, [0, 0])));
    
    return answer;
}