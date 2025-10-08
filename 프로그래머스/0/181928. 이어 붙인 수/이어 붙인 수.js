function solution(num_list) {
    const [a, b] = num_list.reduce((acc, el) => {
        acc[el % 2 ? 1 : 0] += el;
        return acc;
    }, ['', ''])
    
    return ~~a + ~~b;
}