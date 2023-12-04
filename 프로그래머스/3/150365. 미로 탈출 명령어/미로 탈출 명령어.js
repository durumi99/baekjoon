
function solution(n, m, x, y, r, c, k) {
    const MAX = 51;
    const dx = [1, 0, 0, -1];
    const dy = [0, -1, 1, 0];
    const dc = ['d', 'l', 'r', 'u'];

    let N, M, X, Y, R, C, K;
    let answer = '';
    const dp = new Array(MAX).fill(null).map(() => new Array(MAX).fill(''));

    function f(n, m, x, y, r, c, k) {
        N = n;
        M = m;
        X = x;
        Y = y;
        R = r;
        C = c;
        K = k;
    }

    function isImpossible(x, y, remainK) {
        const pathLen = Math.abs(x - R) + Math.abs(y - C);
        if (Math.abs(pathLen - remainK) % 2 !== 0)
            return true;
        if (pathLen > remainK)
            return true;
        return false;
    }

    function cmpString(A, B) {
        const len = Math.min(A.length, B.length);

        for (let i = 0; i < len; i++) {
            if (A[i] < B[i])
                return true;
        }

        return false;
    }

    function dfs(curX, curY) {
        const remainK = K - dp[curX][curY].length;

        if (isImpossible(curX, curY, remainK)) {
            return;
        }

        for (let i = 0; i < 4; i++) {
            const ny = curY + dy[i];
            const nx = curX + dx[i];

            if (ny <= 0 || nx <= 0 || ny > M || nx > N)
                continue;

            const tmp = dp[curX][curY] + dc[i];
            if (tmp.length > K)
                continue;

            if (cmpString(dp[nx][ny], tmp))
                continue;

            dp[nx][ny] = tmp;
            dfs(nx, ny);
        }
    }

    f(n, m, x, y, r, c, k);
    if (isImpossible(x, y, k))
        return "impossible";

    dfs(x, y);
    answer = dp[r][c];
    return answer;
}
