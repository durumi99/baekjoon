let N, M, R, C;
let answer = 'impossible';

const dx = [1, 0, 0, -1];
const dy = [0, -1, 1, 0];
const dc = ['d', 'l', 'r', 'u'];

function solution(n, m, x, y, r, c, k) {
    N = n;
    M = m;
    R = r;
    C = c;
    
    if(getLength(y, x) % 2 !== k % 2) {
        return answer;
    }
    dfs(y, x, k, '');
    return answer;
}

function dfs(curY, curX, curK, curRoute) {
    if(answer !== 'impossible')
        return;
    if(getLength(curY, curX) > curK) {
        return;
    }
    if(curK === 0) {
        if(curX === R && curY === C) {
            answer = curRoute;
        }
        
        return;
    }
    
    for(let i = 0 ; i < 4 ; i++) {
        const nextY = curY + dy[i];
        const nextX = curX + dx[i];
        if(nextY < 1 || nextY < 1 || nextX > N || nextY > M) {
            continue;
        }
        
        dfs(nextY, nextX, curK - 1 , curRoute + dc[i]);
    }
}

function getLength(curY, curX) {
    return Math.abs(curX - R) + Math.abs(curY - C);
}