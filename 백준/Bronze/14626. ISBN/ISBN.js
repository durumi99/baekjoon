const readline = require("readline");

(async () => {
  const rl = readline.createInterface({
    input: process.stdin,
  });

  const input = [];

  for await (const line of rl) {
    input.push(line.trim());
  }
  
  const str = input[0];
  let targetIndex = -1;
  let targetWeight = 1;
  let sum = 0;
  for(let i = 0 ; i < str.length - 1 ; i++) {
    const weight = (i % 2 === 0) ? 1 : 3; 
    if(str[i] === '*') {
      targetIndex = i;
      targetWeight = weight;
    } else {
      sum += Number(str[i]) * weight;
    }
  }
  sum += Number(str[str.length - 1]);
  for(let digit = 0 ; digit <= 9 ; digit++) {
    if((sum + digit * targetWeight) % 10 === 0) {
      console.log(digit);
      break;
    }
  }
  process.exit();
})();