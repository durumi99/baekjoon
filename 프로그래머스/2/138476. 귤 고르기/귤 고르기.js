function solution(k, tangerine) {
    var answer = 0;
    const len = Math.max(...tangerine);
    answer = len;
    let arr = Array.from({length : len + 1}, () => 0);
    
    // tangerine.sort();
    tangerine.map(function (v, k) {
        arr[v]++;
    });
    
    arr.sort((a, b) => (a - b));
    arr.reverse();
    // arr.pop();
    console.log(arr);
    
    for(let i = 0 ; i < arr.length; i++) {
        k -= arr[i];
        if(k <= 0) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}