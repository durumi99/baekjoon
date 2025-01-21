function solution(r1, r2) {
    let answer = 0;

    for (let x = 1; x <= r2; x++) {
        let maxY = Math.floor(Math.sqrt(r2 * r2 - x * x)); // 큰 원 내부의 y 좌표 최대값
        let minY = (r1 * r1 - x * x >= 0) ? Math.ceil(Math.sqrt(r1 * r1 - x * x)) : 0; // NaN 방지

        answer += (maxY - minY + 1);
    }

    return answer * 4; // 1/4분면 기준이므로 전체 4배
}