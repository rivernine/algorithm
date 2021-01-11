#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[100][100];
int ansArr[100][100] = { -1 };
int visited[100][100] = { 0 };
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };

struct Status {
	int a, b, cost;
};

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ansArr[i][j] << " ";
		}cout << endl;
	}
}

void initBFS(Status status, int idx) {
	queue<Status> que;
	que.push(status);
	while (!que.empty()) {
		Status fnt = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int tmpa = fnt.a + da[i];
			int tmpb = fnt.b + db[i];
			if (tmpa < 0 || tmpa >= N || tmpb < 0 || tmpb >= N)
				continue;
			if (arr[tmpa][tmpb] == 1 && !visited[tmpa][tmpb]) {
				visited[tmpa][tmpb] = true;
				arr[tmpa][tmpb] = idx;
				que.push({ tmpa, tmpb, 0 });
			}
		}
	}
}

int BFS(Status status) {
	int idx = arr[status.a][status.b];
	bool visited[100][100] = { 0 };
	queue<Status> que;
	que.push(status);
	visited[status.a][status.b] = true;

	while (!que.empty()) {
		Status fnt = que.front();
		que.pop();

		//cout << "fnt: " << fnt.a << ", " << fnt.b << ", " << fnt.cost << endl;

		for (int i = 0; i < 4; i++) {
			int tmpa = fnt.a + da[i];
			int tmpb = fnt.b + db[i];
			if (tmpa < 0 || tmpa >= N || tmpb < 0 || tmpb >= N)
				continue;
			if (!visited[tmpa][tmpb]) {
				if (arr[tmpa][tmpb] == 0) {
					visited[tmpa][tmpb] = true;
					que.push({ tmpa, tmpb, fnt.cost + 1 });
				}
				else if (arr[tmpa][tmpb] != idx) {
					return fnt.cost;
				}
			} 
		}
	}

	return -1;
}

int main() {
	int answer = 100001;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	int idx = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (arr[i][j] == 1 && !visited[i][j]) {
				visited[i][j] = true;
				arr[i][j] = idx;
				initBFS({ i, j, 0 }, idx++);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ansArr[i][j] == 0 && arr[i][j] != 0) {
				ansArr[i][j] = BFS({ i,j, 0 });
				answer = ansArr[i][j] < answer && ansArr[i][j] != -1 ? ansArr[i][j] : answer;
			}
		}
	}

	//print();

	cout << answer << endl;

	return 0;
}