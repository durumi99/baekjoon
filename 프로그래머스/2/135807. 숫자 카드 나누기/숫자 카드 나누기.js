function solution(arrayA, arrayB) {
    var answer = 0;

    const canDivideAll = (arr, N) => arr.every((el) => el % N === 0);
    const canDivideNone = (arr, N) => arr.every((el) => el % N !== 0);

    let minA = (arrayA.sort()[0]);
    let minB = Math.min(arrayB.sort()[0]);
    let maxN = Math.max(minA, minB);

    while (maxN > 0) {        
        if (canDivideAll(arrayA, maxN) && canDivideNone(arrayB, maxN)) {
            return maxN;
        }
        if (canDivideAll(arrayB, maxN) && canDivideNone(arrayA, maxN)) {
            return maxN;
        }
        maxN--;
    }

    return answer;
}