function solution(scores) {
    let answer = 1;
    const wanho = scores[0];
    const wanhoSum = wanho[0] + wanho[1];

    // 1. 근무 태도 내림차순, 동료 평가 오름차순 정렬
    scores.sort((a, b) => b[0] - a[0] || a[1] - b[1]);

    let maxPeerScore = 0;
    let noIncentive = false;

    const filteredScores = [];

    // 2. 필터링 (현재까지 최대 동료 평가 점수보다 낮으면 제외)
    for (let score of scores) {
        const [attitude, peer] = score;
        
        if (peer < maxPeerScore) {
            // 두 점수 모두 낮다면 탈락
            if (score === wanho) {
                return -1;
            }
            continue;
        }

        maxPeerScore = Math.max(maxPeerScore, peer);
        filteredScores.push(score);
    }

    // 3. 완호 순위 계산
    for (let score of filteredScores) {
        if (score[0] + score[1] > wanhoSum) {
            answer++;
        }
    }

    return answer;
}