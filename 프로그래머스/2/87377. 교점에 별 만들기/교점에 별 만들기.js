function solution(line) {
    const meet = new Set();
    const n = line.length;

    // 교점 찾기
    for (let i = 0; i < n; i++) {
        const [a, b, e] = line[i];
        for (let j = i + 1; j < n; j++) { // 중복 계산 방지 (i === j 비교 필요 없음)
            const [c, d, f] = line[j];

            const denominator = a * d - b * c;
            if (denominator === 0) continue; // 평행한 직선인 경우 스킵

            const xNumerator = b * f - e * d;
            const yNumerator = e * c - a * f;

            if (xNumerator % denominator !== 0 || yNumerator % denominator !== 0) continue; // 정수 좌표가 아닌 경우

            const x = xNumerator / denominator;
            const y = yNumerator / denominator;

            meet.add(`${x} ${y}`);
        }
    }

    // 좌표 범위 계산
    const points = [...meet].map(el => el.split(' ').map(Number));
    const minX = Math.min(...points.map(p => p[0]));
    const minY = Math.min(...points.map(p => p[1]));
    const maxX = Math.max(...points.map(p => p[0]));
    const maxY = Math.max(...points.map(p => p[1]));

    // 출력 배열 생성 (메모리 최적화)
    const height = maxY - minY + 1;
    const width = maxX - minX + 1;
    const answer = Array.from({ length: height }, () => '.'.repeat(width));

    // 별(*) 배치
    for (const [x, y] of points) {
        const rowIdx = maxY - y;
        const colIdx = x - minX;
        answer[rowIdx] = answer[rowIdx].substring(0, colIdx) + '*' + answer[rowIdx].substring(colIdx + 1);
    }

    return answer;
}