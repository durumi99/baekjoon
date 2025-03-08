function solution(storage, requests) {
    var answer = 0;
    const dy = [-1, 0, 0, 1] ;
    const dx = [0, -1 , 1, 0];
    const n = storage.length;
    const m = storage[0].length;
    answer = n * m;
    
    let arrSto = storage.map((el) => {
       return el.split(''); 
    });
    
    const deepCopy = (arr) => JSON.parse(JSON.stringify(arr));
    
    const dfs = (y, x, visited) => {
        // console.log(visited);
        let result = false;
        
        for (let k = 0 ; k < 4 ; k++) {
            const nY = y + dy[k];
            const nX = x + dx[k];
            
            if(nY === -1 || nX === -1 || nY === n || nX === m) {
                return true;
            }
            
            if(visited[nY][nX]) {
                continue;
            }
            
            visited[nY][nX] = true;
            
            if(arrSto[nY][nX] === ' ') {
                result = result || dfs(nY, nX, visited);
            }
        }
        
        return result;
    };
    
    requests.forEach((request) => {
        let tmp = deepCopy(arrSto);
        
        if(request.length === 2) {
            for (let i = 0 ; i < n ; i++) {
                for (let j = 0 ; j < m ; j++) {
                    if(arrSto[i][j] !== request[0]) {
                        continue;
                    }
                    tmp[i][j] = ' ';
                    answer--;
                }
            }
        } else {
            for (let i = 0 ; i < n ; i++) {
                for (let j = 0 ; j < m ; j++) {
                    if(arrSto[i][j] !== request) {
                        continue;
                    }
                    if(i === 0 || j === 0 || i === n - 1 || j === m - 1) {
                        tmp[i][j] = ' ';
                        answer--;
                    } else if(dfs(i, j, Array.from(new Array(n), () => new Array(m).fill(false)))){
                        tmp[i][j] = ' ';
                        answer--;
                    }
                }
            }
        }
        arrSto = tmp;
    });
    
    return answer;
}