function solution(survey, choices) {
    let scores = new Map();
    scores.set('R', 0);
    scores.set('T', 0);
    scores.set('C', 0);
    scores.set('F', 0);
    scores.set('J', 0);
    scores.set('M', 0);
    scores.set('A', 0);
    scores.set('N', 0);
    
    var answer = '';
    choices.forEach((choice, index) => {
        scores.set(survey[index][0], scores.get(survey[index][0]) + 4 - choice);
        scores.set(survey[index][1], scores.get(survey[index][1]) + choice - 4);
    })
    
    
    if(scores.get('R')>= 0) {
        answer += 'R';
    } else {
        answer += 'T';
    }
    
    if(scores.get('C') >= 0) {
        answer += 'C';
    } else {
        answer += 'F';
    }
    
    if(scores.get('J')>= 0) {
        answer += 'J';
    } else {
        answer += 'M';
    }
    
    if(scores.get('A') >= 0) {
        answer += 'A';
    } else {
        answer += 'N';
    }
    return answer;
}