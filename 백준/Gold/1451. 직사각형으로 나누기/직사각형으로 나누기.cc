#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[50][50];

int sumR(int startY, int endY, int startX, int endX){
	int tmp = 0;

	for(int i = startY ; i < endY; i++) {
		for(int j = startX ; j < endX ; j++){
			tmp += map[i][j];
		}
	}

	return tmp;
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long maxSum = -1;
	long long rec[3];
	int N, M; cin >> N >> M;

	for(int i = 0 ; i < N ; i++){
		string s; cin >> s;
		for(int j = 0 ; j < M ; j++){
			map[i][j] = s[j]-'0';
		}
	}
	// 세로로 3등분 〓
	for(int i = 1 ; i < N-1 ; i++) {
		for(int j = i + 1 ; j < N ; j++) {
			rec[0] = sumR(0, i, 0, M);
			rec[1] = sumR(i, j, 0, M);
			rec[2] = sumR(j, N, 0, M);
			maxSum = max(maxSum, rec[0] * rec[1] * rec[2]);
		}
	}
	// 가로로 3등분 ||
	for(int i = 1 ; i < M-1 ; i++) {
		for(int j = i + 1 ; j < M ; j++) {
			// 0번 사각형 0 ~ (i-1)
			// 1번 사각형 i ~ (j-1)
			// 2번 사각형 j ~ (N-1)
			rec[0] = sumR(0, N, 0, i);
			rec[1] = sumR(0, N, i, j);
			rec[2] = sumR(0, N, j, M);
			maxSum = max(maxSum, rec[0] * rec[1] * rec[2]);
		}
	}
	// 세로로 한번 가로로 한번 자를 때
	for(int i = 1 ; i < M ; i++){
		for(int j = 1 ; j < N ; j++) {
			// cout << i << ' ' << j << '\n';
			long long rec2[4];
			rec2[0] = sumR(0, j, 0, i);
			rec2[1] = sumR(0, j, i, M);
			rec2[2] = sumR(j, N, 0, i);
			rec2[3] = sumR(j, N, i, M);
			maxSum = max(maxSum, (rec2[0] + rec2[1]) * rec2[2] * rec2[3]);
			maxSum = max(maxSum, (rec2[0] + rec2[2]) * rec2[1] * rec2[3]);
			maxSum = max(maxSum, (rec2[1] + rec2[3]) * rec2[0] * rec2[2]);
			maxSum = max(maxSum, (rec2[2] + rec2[3]) * rec2[0] * rec2[1]);
		}
	}
	
	cout << maxSum;
    return 0;
}