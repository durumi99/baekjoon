function solution(bandage, health, attacks) {
    var answer = 0;
    let curTime = 0;
    let curHealTime = 0;
    let curHealth = health;
    
    for(let attack of attacks) {
        const healTime = attack[0] - curTime - 1;
        if(attack[0] > curTime) {
            curHealth = Math.min(health, curHealth + (healTime) * bandage[1]);
            curHealth = Math.min(health, curHealth + parseInt(healTime / bandage[0]) * bandage[2]);
            curTime = attack[0];
        }
        curHealth -= attack[1];
        if(curHealth <= 0) {
            return -1;
        }
    }
    answer = curHealth;
    return answer;
}