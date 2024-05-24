function solution(arr) {
    var answer = 1;
    const len = Math.max.apply(null, arr);
    let arr2 = Array.from({length: len + 1}, () => 0);
    
    
    arr.map(function (value, key) {
                let tmp = Array.from({length: value + 1}, () => 0);
                let originValue = value;
                // console.log(Math.sqrt(value));
                for (let i = 2 ; i <= +value ; i++) {
                    while(value % i == 0) {
                        value /= i;
                        tmp[i]++;
                    }
                }

                // console.log("tmp : ", tmp.toString());
                // console.log(value);
                for(let i = 2 ; i <= +originValue ; i++) {
                    // console.log(+arr2[i], +tmp[i]);
                    arr2[i] = Math.max(+arr2[i], +tmp[i]);
                }
                // console.log("Arr2 : ", arr2.toString());
        
            });
    arr2.map(function (value, key) {
        if(value >= 1) {
            // console.log(key, value);
            // console.log(Math.pow(key, value));
            answer *= Math.pow(key, value);
        }
    });
    return answer;
}