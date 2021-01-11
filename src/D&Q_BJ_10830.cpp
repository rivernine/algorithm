#include <iostream>

using namespace std;

int N;
long long B;

struct Status {
	long long arr[5][5] = { 0 };
};
Status I;

Status mul(Status a, Status b) {
	Status result;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				result.arr[i][j] += (a.arr[i][k] * b.arr[k][j]);
			}
			result.arr[i][j] = result.arr[i][j] % 1000;
		}
	}

	return result;
}

Status cal(Status tmp, long long b, Status result) {
	if (b == 2) {
		return mul(mul(tmp, tmp), result);
	} else if (b == 1) {
		return mul(tmp, result);
	} else if (b == 0) {
		return result;
	}

	if (b % 2 == 0) 
		return cal(mul(tmp, tmp), b / 2, result);
	else 
		return cal(mul(tmp, tmp), (b - 1) / 2, mul(tmp, result));
	
}

void init() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (i == j)
				I.arr[i][j] = 1;
}

int main() {
	cin >> N >> B;
	Status status, answer;
	init();

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> status.arr[i][j];
	
	answer = cal(status, B, I);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << answer.arr[i][j] << " ";
		} cout << endl;
	}

	return 0;
}