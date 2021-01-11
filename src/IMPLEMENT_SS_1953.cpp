#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, N, M, R, C, L;
int arr[50][50] = { 0 };
bool visited[50][50] = { false };
//            ╩С го аб ©Л
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };
bool dir2pipe[4][8] = { 0 };
bool pipe2dir[8][4] = { 0 };

struct Status {
	int a, b, time, pipe;
};

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j])
				cout << arr[i][j] << " ";
			else {
				cout << "0" << " ";
			}
		} cout << endl;
	}

}

void initVisited() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
}

void init() {
	dir2pipe[0][1] = true;
	dir2pipe[0][2] = true;
	dir2pipe[0][5] = true;
	dir2pipe[0][6] = true;

	dir2pipe[1][1] = true;
	dir2pipe[1][2] = true;
	dir2pipe[1][4] = true;
	dir2pipe[1][7] = true;

	dir2pipe[2][1] = true;
	dir2pipe[2][3] = true;
	dir2pipe[2][4] = true;
	dir2pipe[2][5] = true;

	dir2pipe[3][1] = true;
	dir2pipe[3][3] = true;
	dir2pipe[3][6] = true;
	dir2pipe[3][7] = true;

	pipe2dir[1][0] = true;
	pipe2dir[1][1] = true;
	pipe2dir[1][2] = true;
	pipe2dir[1][3] = true;

	pipe2dir[2][0] = true;
	pipe2dir[2][1] = true;

	pipe2dir[3][2] = true;
	pipe2dir[3][3] = true;

	pipe2dir[4][0] = true;
	pipe2dir[4][3] = true;

	pipe2dir[5][1] = true;
	pipe2dir[5][3] = true;

	pipe2dir[6][1] = true;
	pipe2dir[6][2] = true;

	pipe2dir[7][0] = true;
	pipe2dir[7][2] = true;
}

int main() {
	cin >> T;

	init();
	for (int testcase = 0; testcase < T; testcase++) {
		initVisited();
		int answer = 0;
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> arr[i][j];

		queue<Status> que;
		que.push({ R, C, L - 1, arr[R][C] });
		visited[R][C] = true;
		answer++;
		while (!que.empty()) {
			Status cur = que.front();
			que.pop();

			//cout << "cur: " << cur.a << ", " << cur.b << ", " << cur.time << endl;
			if (cur.time == 0)	continue;

			for (int i = 0; i < 4; i++) {
				Status next = { cur.a + da[i], cur.b + db[i], cur.time - 1 };
				if (next.a < 0 || next.a >= N || next.b < 0 || next.b >= M)	continue;
				next.pipe = arr[next.a][next.b];

				if (dir2pipe[i][next.pipe] && pipe2dir[cur.pipe][i] && !visited[next.a][next.b]) {
					que.push(next);
					visited[next.a][next.b] = true;
					answer++;
				}
			}
		}

		//print();
		cout << "#" << testcase + 1 << " " << answer << endl;
	}

	return 0;
}