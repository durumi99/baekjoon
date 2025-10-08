function solution(box, n) {
    return box.reduce((acc, el) => {
        return acc * ~~(el / n);
    }, 1);
}