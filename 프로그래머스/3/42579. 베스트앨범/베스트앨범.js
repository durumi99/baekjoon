function solution(genres, plays) {
  const result = []; // 결과 담을 배열
  const obj = {}; // 속한 노래가 많이 재생된 장르 수록할 객체
  const info = {}; // 고유 번호에 따른 재생 횟수와 장르를 담을 객체

  // 장르별로 재생 횟수를 더하고, 고유 번호에 따른 재생 횟수와 장르를 담음
  for (let i = 0; i < genres.length; i++) {
    obj[genres[i]] = (obj[genres[i]] || 0) + plays[i];
    info[i] = { play: plays[i], genre: genres[i] };
  } 

  // 재생 횟수가 많은 장르 순으로 정렬 → 1번 기준
  const sortedGenre = Object.keys(obj).sort((a, b) => obj[b] - obj[a]);

  sortedGenre.forEach((genre) => {
    // 장르별로 재생 횟수가 많은 노래 2개씩 추출
    const genreSong = Object.values(info)
      .filter((song) => song.genre === genre)
      .sort((a, b) => b.play - a.play)
      .slice(0, 2);

    // 고유 번호를 result에 담음
    genreSong.forEach((gs) => {
      const uniqueId = Object.values(info).indexOf(gs);
      result.push(uniqueId);
    });
  });

  return result;
}
