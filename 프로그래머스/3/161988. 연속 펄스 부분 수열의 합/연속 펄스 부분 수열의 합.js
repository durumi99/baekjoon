function solution(sequence) {
    var answer = 0;
    const [arr1, arr2] = [1, -1].map(start =>
        sequence.map((el, i) => el * (i % 2 === 0 ? start : -start))
    );
    
    const kadane = (arr) => {
        let maxSum = arr[0];
        let curSum = arr[0];

        for (let i = 1; i < arr.length; i++) {
            curSum = Math.max(arr[i], curSum + arr[i]);
            maxSum = Math.max(maxSum, curSum);
        }

        return maxSum;
    }

    return Math.max(kadane(arr1), kadane(arr2));
    
    return answer;
}