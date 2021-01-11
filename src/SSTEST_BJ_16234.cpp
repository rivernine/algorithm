#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct Status {
	int a, b;
};
struct Result {
	int total, cnt, team, val;
};
int N, L, R;
int arr[50][50];
int visited[50][50];
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };

void printVisited() {
	cout << "visited" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		} cout << endl;
	}
}

void initVisited() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = 0;
}

Result BFS(int a, int b, int team) {
	//cout << "BFS: " << a << ", " << b << ", " << team << endl;
	Result result = { 0, 0, team };
	queue<Status> que;
	visited[a][b] = team;
	result.cnt++;
	result.total += arr[a][b];
	que.push({ a, b });
	while (!que.empty()) {
		Status cur = que.front();
		//cout << "cur: " << cur.a << ", " << cur.b << endl;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nexta = cur.a + da[i];
			int nextb = cur.b + db[i];
			if (nexta < 0 || nexta >= N || nextb < 0 || nextb >= N)
				continue;
			int diff = abs(arr[cur.a][cur.b] - arr[nexta][nextb]);
			if (visited[nexta][nextb] == 0 && diff >= L && diff <= R) {
				visited[nexta][nextb] = team;
				result.cnt++;
				result.total += arr[nexta][nextb];
				que.push({ nexta, nextb });
			}
		}
	}
	
	result.val = result.total / result.cnt;
	//cout << "result team, val: " << result.team << ", " << result.val << endl;
	return result;
}

void chk(vector<Result> result) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = result[visited[i][j]].val;
		}
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int answer = 0;
	while (true) {
		int team = 1;
		vector<Result> result;
		result.push_back({});
		initVisited();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					result.push_back(BFS(i, j, team++));					
					//printVisited();
				}
			}
		}		
		if (team == N * N + 1) {
			cout << answer << endl;
			break;
		} else {
			chk(result);
			answer++;
		}
	}
	

	return 0;
}