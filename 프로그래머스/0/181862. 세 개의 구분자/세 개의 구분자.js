function solution(myStr) {
    var answer = myStr.replace(/[abc]/g, ' ').split(' ').filter(el => el);
    answer = answer.length ? answer : ['EMPTY'];
    
    return answer;
}