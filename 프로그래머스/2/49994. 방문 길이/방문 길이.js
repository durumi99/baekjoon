function solution(dirs) {
    var answer = 0;
    let curY = 0, curX = 0;
    const dy = [1, -1, 0, 0];
    const dx = [0, 0, 1, -1]
    
    let s = new Set();
    for(let dir of dirs) {
        let nextY, nextX;
        if(dir == "U") {
            nextY = curY + 1;
            nextX = curX;
        } else if(dir == "D") {
            nextY = curY - 1;
            nextX = curX;
        } else if(dir == "R") {
            nextY = curY;
            nextX = curX + 1;
        } else {
            nextY = curY;
            nextX = curX - 1;
        }
        if(nextY > 5 || nextY < -5 || nextX > 5 || nextX < -5) {
            continue;
        }
        s.add((curY + nextY) +""+ (curX + nextX));
        
        curY = nextY;
        curX = nextX;
    }
    return s.size;
}