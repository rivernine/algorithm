#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[8][8];
int tmpArr[8][8];
vector<pair<int, int>> init;
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };
int zeroCount = -3;
int answer = 0;

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j];
		}cout << endl;
	}
}

int BFS() {
	queue<pair<int, int>> que;
	int result = zeroCount;

	for (int i = 0; i < init.size(); i++)
		que.push(init[i]);

	while (!que.empty()) {
		pair<int, int> front = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int tmpa = front.first + da[i];
			int tmpb = front.second + db[i];

			if (tmpa < 0 || tmpa >= N || tmpb < 0 || tmpb >= M)
				continue;
			if (tmpArr[tmpa][tmpb] == 0) {
				tmpArr[tmpa][tmpb] = 2;
				result--;
				if (result < answer)
					return 0;
				que.push(make_pair(tmpa, tmpb));
			}
		}
		
	}

	return result;
}

void copyArr() {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			tmpArr[i][j] = arr[i][j];
}

void makeWall(int cnt) {
	if (cnt == 0 ) {
		copyArr();		
		int tmpAnswer = BFS();
		if (tmpAnswer > answer)
			answer = tmpAnswer;
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				makeWall(cnt - 1);
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for ( int i = 0; i < N; i++ ) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				init.push_back(make_pair(i, j));
			} else if (arr[i][j] == 0) {
				zeroCount++;
			}
		}
	}
	makeWall(3);
	cout << answer << endl;

	return 0;
}