function solution(s){
    var answer = true;
    console.log(s.toUpperCase());
    let cnt = 0;
    s.toUpperCase().split('').forEach((el) => {
        if(el === 'P') {
            cnt++;
        } else if(el === 'Y') {
            cnt--;
        }
    })
    return cnt === 0;
}