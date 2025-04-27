function solution(play_time, adv_time, logs) {
    const playSeconds = timeToSeconds(play_time);
    const advSeconds = timeToSeconds(adv_time);
    const times = new Array(playSeconds + 1).fill(0);

    logs.forEach(log => {
        const [start, end] = log.split('-').map(timeToSeconds);
        times[start] += 1;
        times[end] -= 1;
    });

    for (let i = 1; i <= playSeconds; i++) {
        times[i] += times[i - 1];
    }

    for (let i = 1; i <= playSeconds; i++) {
        times[i] += times[i - 1];
    }
    
    let maxTime = times[advSeconds - 1];
    let maxStart = 0;

    for (let i = advSeconds; i < playSeconds; i++) {
        const currentTime = times[i] - times[i - advSeconds];
        if (currentTime > maxTime) {
            maxTime = currentTime;
            maxStart = i - advSeconds + 1;
        }
    }

    return secondsToTime(maxStart);
}

function timeToSeconds(timeString) {
    const [hours, minutes, seconds] = timeString.split(':').map(Number);
    return hours * 3600 + minutes * 60 + seconds;
}

function secondsToTime(totalSeconds) {
    const hours = Math.floor(totalSeconds / 3600);
    const minutes = Math.floor((totalSeconds % 3600) / 60);
    const seconds = totalSeconds % 60;

    const pad = (num) => String(num).padStart(2, '0');

    return `${pad(hours)}:${pad(minutes)}:${pad(seconds)}`;
}