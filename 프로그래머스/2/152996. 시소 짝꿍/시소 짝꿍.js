function solution(weights, distances = [2,3,4]) {
  const map = new Map();
  let answer = 0;
  
  for (const w of weights) {
    map.set(w, (map.get(w) || 0) + 1);
  }

  for (const [w, count] of map) {
    if (count > 1) {
      answer += count * (count - 1);
    }

    for (const d1 of distances) {
      for (const d2 of distances) {
        if (d1 === d2) continue; 

        const partner = (w * d1) / d2;
        if (Number.isInteger(partner) && map.has(partner)) {
            answer += count * map.get(partner);
        }
      }
    }
  }

  return answer / 2;
}