function solution(n) {
    var answer = new Array(n * n).fill(0);
    let cur = 1;
    let N = n;
    let y = -1, x = 0;
    while(true) {
        // console.log("n : ", n);
        // 위에서 아래로
        let tmp = n;
        
        while(tmp--) {
            y++;
            answer[y * N + x] = cur++;
        }
        n--;
        // console.log(answer.join(' '));
        if(n == 0)
            break;
        // 왼쪽에서 오른쪽으로
        tmp = n;
        while(tmp--) {
            x++;
            answer[y * N + x] = cur++;
        }
        n--;
        // console.log(answer.join(' '));
        if(n == 0)
            break;
        // 왼쪽 위 대각선으로
        
        tmp = n;
        
        while(tmp--) {
            y--;
            x--;
            answer[y * N + x] = cur++;
        }
        n--;
        // console.log(answer.join(' '));
        if(n == 0)
            break;
    }
    // console.log(answer.filter((el) => el != 0).join(' '));
    return answer.filter((el) => el != 0);
}