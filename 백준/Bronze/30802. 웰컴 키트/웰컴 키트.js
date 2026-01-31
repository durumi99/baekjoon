const readline = require("readline");

(async () => {
  const rl = readline.createInterface({
    input: process.stdin,
  });

  const input = [];

  for await (const line of rl) {
    input.push(line.trim());
  }
  
  const N = Number(input[0]); 
  const tshirts = input[1].split(' ').map(Number);
  const [T, P] = input[2].split(' ').map(Number);

  const shirtCount = tshirts.reduce((acc, shirt) => {
    return acc + Math.ceil(shirt / T);
  }, 0);
  const penCount = Math.floor(N / P);

  console.log(shirtCount);
  console.log(penCount, N % P);
  process.exit();
})();