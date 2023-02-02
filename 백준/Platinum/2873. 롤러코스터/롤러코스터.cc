#include <iostream>
#include <cmath>

#define MAX 1001
using namespace std;
int R, C;
int map[MAX][MAX];

int minValue = MAX;
int minY, minX;
string result = "";

void printR() {
	for(int i = 0 ; i < R-1 ; i++) {
		if(i % 2 == 0){
			for(int j = 0 ; j < C-1 ; j++){
				result += "R";
			}
			result += "D";
		} else {
			for(int j = 0 ; j < C-1 ; j++){
				result += "L";
			}
			result += "D";
		}
	}
	for(int j = 0 ; j < C-1 ; j++){
		result += "R";
	}
}
void printC() {
	for(int i = 0 ; i < C-1 ; i++) {
		if(i % 2 == 0){
			for(int j = 0 ; j < R-1 ; j++){
				result += "D";
			}
			result += "R";
		} else {
			for(int j = 0 ; j < R-1 ; j++){
				result += "U";
			}
			result += "R";
		}
	}
	for(int j = 0 ; j < R-1 ; j++){
		result += "D";
	}
}

void print() {
	int newR = minY % 2 ? minY : minY-1; 

	for(int i = 1 ; i < newR ; i++) {
		for(int j = 0 ; j < C-1 ; j++) {
			if(i % 2) {
				result += "R";
			} else {
				result += "L";
			}
		}
		result += "D";
	}
	int newC = minX;
	
	for(int i = 1 ; i < newC ; i++) {
		if(i % 2) {
			result += "DR";
		} else {
			result += "UR";
		}
	}
	
	for (int i = newC ; i < C ; i++) {
			if (i % 2)
				result += "RD";
			else
				result += "RU";
		}
		
	
	for (int i = newR + 2; i <= R; i++) {
		result += 'D';
		for (int j = 0; j < C-1 ; j++) {
			if (i % 2)
				result += 'L';
			else
				result += 'R';
		}
	}
}
int main() {
	cin >> R >> C;
	
	for (int i = 1 ; i <= R ; i++) {
		for(int j = 1 ; j <= C ; j++) {
			cin >> map[i][j];
			if((i+j) % 2 == 0)
				continue;
			if(minValue > map[i][j]) {
				minValue = map[i][j];
				minY = i;
				minX = j;
			}
		}
	}
    
	if (R % 2) {
		printR();
	} else if(C % 2) {
		printC();
	} else {
		print();
	}
	cout << result;
	return 0;
}