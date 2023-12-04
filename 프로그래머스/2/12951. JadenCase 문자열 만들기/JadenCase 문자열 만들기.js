function solution(s) {
    var answer = '';
//     answer = [...s].forEach( (el, idx, curArr) => {
//         console.log(el, idx)
//         // console.log(curArr)
//         if(idx == 0 || s[idx - 1] === ' ') {
//             curArr[idx] = curArr[idx].toUpperCase();
//         } else {
//             curArr[idx] = curArr[idx].toLowerCase();
//         }
//         answer += curArr[idx]
//     })
    
    for(let idx = 0 ; idx < s.length ; idx++) {
        if(idx == 0 || s[idx - 1] === ' ') {
            answer += s[idx].toUpperCase();
        } else {
            answer += s[idx].toLowerCase();
        }
    }
    return answer;
}