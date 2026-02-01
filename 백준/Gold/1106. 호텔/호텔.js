const readline = require("readline");

(async () => {
  const rl = readline.createInterface({
    input: process.stdin,
  });

  const input = [];

  for await (const line of rl) {
    input.push(line.trim());
  }
  const [C, N] = input[0].split(" ").map(Number);
  const arr = [];

  for (let i = 1; i <= N; i++) {
    const [cost, people] = input[i].split(" ").map(Number);
    arr.push({ cost, people });
  }

  const maxPeople = C + 100;
  const dp = new Array(maxPeople + 1).fill(Infinity);

  dp[0] = 0;

  for (const { cost, people } of arr) {
    for (let j = people; j <= maxPeople; j++) {
        
      if (dp[j - people] !== Infinity) {
        dp[j] = Math.min(dp[j], dp[j - people] + cost);
      }
    }
  }

  let answer = Infinity;
  for (let i = C; i <= maxPeople; i++) {
    answer = Math.min(answer, dp[i]);
  }

  console.log(answer);
  process.exit();
})();