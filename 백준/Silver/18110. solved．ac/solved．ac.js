const readline = require("readline");

(async () => {
  const rl = readline.createInterface({
    input: process.stdin,
  });

  const input = [];

  for await (const line of rl) {
    input.push(line.trim());
  }
  const n = Number(input[0]);
  if(n === 0) {
    console.log(0);
    process.exit();
  }
  const arr = [];
  for(let i = 1; i <= n; i++) {
    arr.push(Number(input[i]));
  }
  arr.sort((a, b) => a - b);
  const excludeCount = Math.round(n * 0.15);
  let sum = 0;
  for(let i = excludeCount; i < n - excludeCount; i++) {
    sum += arr[i];  
  }

  const average = Math.round(sum / (n - 2 * excludeCount));
  console.log(average);
  
  process.exit();
})();