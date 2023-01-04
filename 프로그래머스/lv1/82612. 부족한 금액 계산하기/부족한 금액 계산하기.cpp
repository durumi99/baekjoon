using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long priceSum = -money;
    for(int i = 1 ; i <= count ; i++) {
        priceSum += price * i;
    }
    // answer = priceSum - money;
    answer = priceSum;
    if (answer < 0)
        return 0;
    return answer;
}