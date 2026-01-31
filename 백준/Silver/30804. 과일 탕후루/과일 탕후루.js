const readline = require("readline");

(async () => {
  const rl = readline.createInterface({
    input: process.stdin,
  });

  const input = [];

  for await (const line of rl) {
    input.push(line.trim());
  }

  let idx = 0;

  const [N] = input[idx++].split(" ").map(Number);
  const arr = input[idx++].split(" ").map(Number);
  let answer = -1;
  const fruits = new Map();
  let left = 0;
  let right = 0;
  fruits.set(arr[0], 1);
  while(left <= right && right < arr.length) {
    if(fruits.size <= 2) {
      answer = Math.max(answer, right - left + 1);
      right++;
      const rightFruit = arr[right];
      const rightCnt = fruits.get(rightFruit) || 0;
      fruits.set(rightFruit, rightCnt + 1);
    } else {
      const leftFruit = arr[left];
      const leftCnt = fruits.get(leftFruit);
      if(leftCnt === 1) {
        fruits.delete(leftFruit);
      } else {
        fruits.set(leftFruit, leftCnt - 1);
      }

      left++;
    }
  }

  console.log(answer);
  process.exit();
})();