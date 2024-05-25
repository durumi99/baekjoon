function solution(arr1, arr2) {
    var answer = Array.from({length: arr1.length},() => Array(arr2[0].length).fill(0));
    
    // console.log(answer);
    for(let i = 0 ; i < arr1.length ; i++) {
        for(let j = 0 ; j < arr2[0].length ; j++) {
            answer[i][j] = 0;
            for(let k = 0 ; k < arr2.length ; k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
            // console.log(answer);
        }
    }
    return answer;
}