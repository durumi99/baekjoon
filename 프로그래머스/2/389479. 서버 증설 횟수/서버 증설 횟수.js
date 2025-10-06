function solution(players, m, k) {
    var answer = 0;
    let curServers = [Infinity];
    
    players.forEach((player, idx) => {
        curServers = curServers.filter(server => server > idx);
        
        while(needExpansion(player, curServers.length, m)) {
            curServers.push(idx + k);
            answer++;
        } 
    });
    
    return answer;
}

function needExpansion(player, n, m) {
    return player >= n * m;
}