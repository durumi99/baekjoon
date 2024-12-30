function solution(fees, records) {
    var answer = [];
    let parkingFees = new Map();
    records.forEach((record) => {
        const recordArray = record.split(' ');
        const timeString = recordArray[0];
        const formattedTime = ~~timeString.slice(0, 2) * 60 + ~~timeString.slice(3);
        const carNumber = recordArray[1];
        const isIn = recordArray[2] === 'IN';
        
        if(!parkingFees.has(carNumber)) { // 신규 차량
            parkingFees.set(carNumber, [formattedTime, 0, true]); // 입차시각, 누적 주차 시간, 입차 여부
            
        } else if (!isIn){ // 기존 차량 출차
            const prevInTime = parkingFees.get(carNumber)[0];
            const prevCumTime = parkingFees.get(carNumber)[1];
            // console.log(carNumber, prevCumTime, formattedTime,  prevInTime);
            parkingFees.set(carNumber, [formattedTime, prevCumTime + formattedTime - prevInTime, false]);
            
        } else { // 기존 차량 재입차
            const prevCumTime = parkingFees.get(carNumber)[1];
            parkingFees.set(carNumber, [formattedTime, prevCumTime , true]);
        }
        // console.log(parkingFees);
    })
    parkingFees.forEach((value, key) => {
        if(value[2] === true) {      
            const formattedTime = 23 * 60 + 59;
            const prevInTime = value[0];
            const prevCumTime = value[1];
            
            parkingFees.set(key, [formattedTime, prevCumTime + formattedTime - prevInTime, false])
        }
        
    })
    
    const finalParkingFees = [...parkingFees].sort();
    finalParkingFees.forEach((fee) => {
        const time = fee[1][1];
        if(time <= fees[0]) {
            answer.push(fees[1]);
        } else {
            answer.push(fees[1] + fees[3] * Math.ceil((time - fees[0]) / fees[2]));
        }
    })
    return answer;
}