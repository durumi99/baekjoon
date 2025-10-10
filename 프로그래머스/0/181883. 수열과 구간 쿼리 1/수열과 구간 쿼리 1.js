function solution(arr, queries) {
    queries.forEach(([start, end]) => {
        for(let i = start; i <= end ; i++) {
            arr[i]++; 
        }
    });
    return arr;
}