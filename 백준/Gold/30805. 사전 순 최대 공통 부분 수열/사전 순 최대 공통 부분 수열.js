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
  let A = input[1].split(" ").map(Number);
  const m = Number(input[2]);
  let B = input[3].split(" ").map(Number);
  const result = [];
  
  while (true) {
    let maxVal = -1;
    let maxIdxA = -1;
    let maxIdxB = -1;

    for (let i = 0; i < A.length; i++) {
      const val = A[i];
      if (val <= maxVal) continue;

      const foundInB = B.indexOf(val);
      if (foundInB !== -1) {
        maxVal = val;
        maxIdxA = i;
        maxIdxB = foundInB;
      }
    }

    if (maxVal === -1) break;

    result.push(maxVal);

    A = A.slice(maxIdxA + 1);
    B = B.slice(maxIdxB + 1);
  }

  console.log(result.length);
  if (result.length > 0) {
    console.log(result.join(' '));
  }
  process.exit();
})();