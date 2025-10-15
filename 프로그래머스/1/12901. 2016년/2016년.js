function solution(a, b) {
    const days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    const weeks = ['SUN','MON','TUE','WED','THU','FRI','SAT'];
    const tmp = (days.slice(0, a - 1).reduce((acc, el) => acc + el, 0) + b) % 7;
    return weeks[(tmp + 4) % 7];
}