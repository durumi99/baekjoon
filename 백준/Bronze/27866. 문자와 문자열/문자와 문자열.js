const readline = require("readline");

(async () => {
  const rl = readline.createInterface({
    input: process.stdin,
  });

  const input = [];

  for await (const line of rl) {
    input.push(line.trim());
  }
  
  const s = input[0];
  const i = Number(input[1]);

  console.log(s[i - 1]);
  process.exit();
})();