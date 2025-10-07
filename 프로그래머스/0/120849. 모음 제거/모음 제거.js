function solution(my_string) {
    const target = ['a', 'e', 'i', 'o', 'u'];
    
    var answer = my_string.split('').filter(el => !target.includes(el)).join('');
    return answer;
}