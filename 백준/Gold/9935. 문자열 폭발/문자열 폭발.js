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

  const str = input[idx++];
  const target = input[idx++];
  let answer = [];

  for(const c of str) {
    answer.push(c);
    if(c === target.at(-1)) {
      if(target === answer.slice(-target.length).join('')) {
        for(let i = 0 ; i < target.length ; i++) {
          answer.pop();
        }
      }
    }
  }


  if(answer.length === 0) {
    console.log('FRULA');
  } else {
    console.log(answer.join(''));  
  }
  
  process.exit();
})();