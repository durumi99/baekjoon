#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    int maxTeam = 0;
	int N, M, K; cin >> N >> M >> K;
	for(int i = 0 ; i <= K ; i++) {
		int female = N - i;
		int male = M - (K-i);
		int team = min(female/2, male);
		maxTeam = max(team, maxTeam);
	}
	
	cout << maxTeam;
	return 0;
}