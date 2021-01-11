#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

struct Status {
	int a, b;
};
int N, M;
int arr[50][50];
vector<Status> store(13);
bool isRun[13] = { 1 };
int totalStore = 0;
int answer = INT_MAX;

void print() {
	for (int i = 0; i < totalStore; i++) {
		cout << isRun[i] << " ";
	} cout << endl;
}

int ckDistance() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				int dist = INT_MAX;
				for (int k = 0; k < totalStore; k++) {
					if (isRun[k]) {
						int tmp = abs(store[k].a - i) + abs(store[k].b - j);
						dist = tmp < dist ? tmp : dist;
					}
				}
				result += dist;
			}
		}
	}

	return result;
}

void select(int cnt, int idx) {
	int tmp = ckDistance();
	//print();b
	//cout << "tmpAns: " << tmp << endl;

	answer = tmp < answer && tmp > 0 ? tmp : answer;

	if (cnt == 0) {
		return;
	}

	for (int i = idx; i < totalStore; i++) {
		isRun[i] = true;
		select(cnt - 1, i + 1);
		isRun[i] = false;
	}

}

int main() {
	cin >> N >> M;
	totalStore = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				store[totalStore] = { i, j };
				isRun[totalStore++] = false;
			}
		}
	}

	select(M, 0);
	cout << answer << endl;


	return 0;
}