#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[300][300];
int tmpArr[300][300];
bool visited[300][300] = { 0 };
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };

struct Status {
	int a, b;
};

void tmpToArr() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmpArr[i][j] < 0)
				arr[i][j] = 0;
			else
				arr[i][j] = tmpArr[i][j];
		}
	}
}

void arrToTmp() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmpArr[i][j] = arr[i][j];
}

bool melt() {
	int cnt = 0;
	arrToTmp();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					int tmpa = i + da[k];
					int tmpb = j + db[k];
					if (tmpa < 0 || tmpa >= N || tmpb < 0 || tmpb >= M)
						continue;

					if (arr[tmpa][tmpb] > 0)
						tmpArr[tmpa][tmpb]--;
				}
			}
			else {
				cnt++;
			}
		}
	}
	tmpToArr();

	if (cnt == 0)
		return false;
	else
		return true;

}

void initVisited() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
}

void BFS(Status status) {
	queue<Status> que;
	que.push(status);
	while (!que.empty()) {
		Status fnt = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int tmpa = fnt.a + da[i];
			int tmpb = fnt.b + db[i];
			if (tmpa < 0 || tmpa >= N || tmpb < 0 || tmpb >= M)
				continue;
			if (arr[tmpa][tmpb] != 0 && !visited[tmpa][tmpb]) {
				visited[tmpa][tmpb] = true;
				que.push({ tmpa, tmpb });
			}
		}
	}
}

int main() {
	int answer = 0;
	bool isPossible = false;

	cin >> N >> M;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> arr[i][j];

	while (true) {
		answer++;
		bool canMelt = melt();
		int cnt = 0;
		initVisited();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 0 && !visited[i][j]) {
					visited[i][j] = true;
					BFS({ i, j });
					cnt++;
				}
			}
		}

		if (cnt >= 2) 
			isPossible = true;		

		if (!canMelt || isPossible )
			break;
	}

	cout << (isPossible ? answer : 0) << endl;

	return 0;
}