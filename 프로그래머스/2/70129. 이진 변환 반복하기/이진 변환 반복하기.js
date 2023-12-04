function solution(s) {
    var answer = [];
    let cnt = 0
    let cnt2 = 0
    while(s != '1') {
        cnt2++
        // let tmp = [...s].filter(x => x == 1)
        // cnt += s.length = tmp.length
        // c
        let newStr = s.replace(/0/g,'');
        cnt += s.length - newStr.length     
        // console.log(s)
        // console.log(newStr)
        // s = parseInt('6%abc', 2)
        s = newStr.length.toString(2)
        // console.log(s)
        // break
    }
    answer = [cnt2, cnt]
    
    
    return answer;
}