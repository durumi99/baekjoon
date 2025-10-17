function solution(order) {
    const orderMap = new Map();
    orderMap.set("iceamericano", 4500);
    orderMap.set("americanoice", 4500);
    orderMap.set("hotamericano", 4500);
    orderMap.set("americanohot", 4500);
    orderMap.set("americano", 4500);
    orderMap.set("anything", 4500);
    
    orderMap.set("icecafelatte", 5000);
    orderMap.set("cafelatteice", 5000);
    orderMap.set("hotcafelatte", 5000);
    orderMap.set("cafelattehot", 5000);
    orderMap.set("cafelatte", 5000);
    
    var answer = order.reduce((acc, el) => acc + orderMap.get(el), 0);
    return answer;
}