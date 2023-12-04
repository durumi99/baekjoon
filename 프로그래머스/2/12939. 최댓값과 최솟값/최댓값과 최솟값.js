function solution(s) {
    var answer = '';
    const arr = s.split(' ')
    console.log(arr)
    const arr2 = arr.map((e) => parseInt(e))
    console.log(arr2)
    const maxValue = Math.max.apply(null, arr);
    const minValue = Math.min.apply(null, arr);
    answer = `${minValue} ${maxValue}`
    return answer;
}