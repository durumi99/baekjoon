function solution(n)
{
    var ans = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    while(n != 0) {
        // console.log(n, ans);
        // while(n % 2 == 0) {
        //     n /= 2;
        // }
        if(n % 2 == 1) {
            ans++;
        }
        n = Math.floor(n / 2);
    }
    return ans;
}