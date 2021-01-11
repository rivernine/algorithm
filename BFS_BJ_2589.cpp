#include <iostream>
#include <queue>

using namespace std;

int N, M;
char arr[50][50];
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1 ,1 };

struct Status {
	int a, b, cost;
};

int BFS(int a, int b) {
	int result = 0;
	queue<Status> que;
	bool visited[50][50] = { 0 };

	que.push({ a, b, 0 });
	visited[a][b] = true;
	while (!que.empty()) {
		Status front = que.front();
		result = front.cost;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int tmpa = front.a + da[i];
			int tmpb = front.b + db[i];
			if (tmpa < 0 || tmpa >= N || tmpb < 0 || tmpb >= M)
				continue;
			if ( arr[tmpa][tmpb] == 'L' && !visited[tmpa][tmpb]) {
				visited[tmpa][tmpb] = true;
				que.push({ tmpa, tmpb, front.cost + 1 });
			}
		}
	}

	return result;
}

int main() {
	int answer = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'L') {
				int tmp = BFS(i, j);
				if (tmp > answer)
					answer = tmp;
			}
		}
	}

	cout << answer << endl;

	return 0;
}