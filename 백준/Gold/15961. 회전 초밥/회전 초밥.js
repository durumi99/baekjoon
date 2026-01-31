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
  const [N, d, k ,c] = input[idx++].split(" ").map(Number);
  const sushiBelt = [];
  for (let i = 0; i < N; i++) {
    sushiBelt.push(Number(input[idx++]));
  }
  sushiBelt.push(...sushiBelt.slice(0, k));
  const sushiCount = new Int32Array(d + 1);
  let answer = 0;
  let uniqueSushi = 0;
  let right = k - 1;
  
  for(let i = 0 ; i < k ; i++) {
    if(sushiCount[sushiBelt[i]] === 0) uniqueSushi++;
    sushiCount[sushiBelt[i]]++;
  }

  for(let i = 0 ; i < N ; i++) {
    if(sushiCount[sushiBelt[i]] === 1) uniqueSushi--;
    sushiCount[sushiBelt[i]]--;
    
    right++;
    if(sushiCount[sushiBelt[right]] === 0) uniqueSushi++;
    sushiCount[sushiBelt[right]]++;

    if(sushiCount[c] === 0) {
      answer = Math.max(uniqueSushi + 1, answer);
    }
    answer = Math.max(uniqueSushi,answer);
  }
  
  console.log(answer);
  process.exit();
})();