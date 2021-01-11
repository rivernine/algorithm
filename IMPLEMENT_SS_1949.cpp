#include <iostream>

using namespace std;

int T, N, K;
int arr[8][8];
bool visited[8][8] = { 0 };
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };
int answer;

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		} cout << endl;
	}
}

void DFS(int a, int b, int item, int len, bool flag) {
	/*print();
	cout << "a, b, item, len: " << a << ", " << b << ", " << item << ", " << len << endl;*/
	answer = len > answer ? len : answer;

	for (int i = 0; i < 4; i++) {
		int nexta = a + da[i];
		int nextb = b + db[i];
		if (nexta < 0 || nexta >= N || nextb < 0 || nextb >= N)
			continue;

		if (arr[nexta][nextb] < arr[a][b] && !visited[nexta][nextb]) {
			visited[nexta][nextb] = true;
			DFS(nexta, nextb, item, len + 1, flag);
			visited[nexta][nextb] = false;
		}
		else if(arr[nexta][nextb] >= arr[a][b] && !visited[nexta][nextb] && !flag) {
			int bef = arr[nexta][nextb];
			int work = arr[nexta][nextb] - arr[a][b] + 1;
			if (work <= item) {
				visited[nexta][nextb] = true;
				arr[nexta][nextb] = arr[nexta][nextb] - work;
				DFS(nexta, nextb, item - work, len + 1, true);
				visited[nexta][nextb] = false;
				arr[nexta][nextb] = bef;
			}
		}
	}
}

int main() {
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		cin >> N >> K;

		int highest = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				highest = arr[i][j] > highest ? arr[i][j] : highest;
			}
		}

		answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == highest) {
					visited[i][j] = true;
					DFS(i, j, K, 1, false);
					visited[i][j] = false;
				}
			}
		}

		cout << "#" << testcase + 1 << " " << answer << endl;
	}


	return 0;
}