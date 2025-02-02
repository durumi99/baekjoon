function solution(line) {

    const meet = new Set();
    line.forEach(([a, b, e], idx1) => {
        line.forEach(([c, d, f], idx2) => {
            if(idx1 === idx2) {
                return;
            }
            if(a * d - b * c === 0) {
                return;
            }
            
            if((b * f - e * d) % (a * d - b * c)) {
                return;
            } 
            
            if((e * c - a * f) % (a * d - b * c)) {
                return;
            } 
            
            const x = (b * f - e * d) / (a * d - b * c);
            const y = (e * c - a * f) / (a * d - b * c);
            
            
            meet.add(`${x} ${y}`);
        });
    });
    const points = [...meet].map(el => el.split(' ').map(Number));
    const minX = Math.min(...points.map(p => p[0]));
    const minY = Math.min(...points.map(p => p[1]));
    const maxX = Math.max(...points.map(p => p[0]));
    const maxY = Math.max(...points.map(p => p[1]));
    
    const height = maxY - minY + 1;
    const width = maxX - minX + 1;
    const answer = Array.from({ length: height }, () => '.'.repeat(width));

    for (let j = minY; j <= maxY; j++) {
        let row = '';
        for (let i = minX; i <= maxX; i++) {
            row += meet.has(`${i} ${j}`) ? '*' : '.';
        }
        answer[maxY - j] = row; 
    }

    return answer;
}