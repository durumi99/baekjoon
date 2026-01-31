const readline = require("readline");

(async () => {
  const rl = readline.createInterface({
    input: process.stdin,
  });

  const input = [];

  for await (const line of rl) {
    input.push(line.trim());
  }
  
  const checkFizzBuzz = (num) => {
    if (num % 3 === 0 && num % 5 === 0) {
      return "FizzBuzz";
    } else if (num % 3 === 0) {
      return "Fizz";  
    } else if (num % 5 === 0) {
      return 'Buzz';
    }
    return num;
  };
  let answer;
  if(!isNaN(input[0])) {
    answer = checkFizzBuzz(Number(input[0]) + 3);
  } else if(!isNaN(input[1])) {
    answer = checkFizzBuzz(Number(input[1]) + 2);
  } else {
    answer = checkFizzBuzz(Number(input[2]) + 1);
  }
  
  console.log(answer);
  process.exit();
})();