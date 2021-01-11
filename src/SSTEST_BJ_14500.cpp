#include <iostream>

using namespace std;

int N, M;
int arr[500][500];
bool visited[500][500];
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };
int answer = 0;

void DFS(int a, int b, int cnt, int sum) {
	//cout << "a, b, cnt, sum: " << a << ", " << b << ", " << cnt << ", " << sum << endl;
	if (cnt == 4) {
		answer = sum > answer ? sum : answer;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nexta = a + da[i];
		int nextb = b + db[i];

		if (nexta < 0 || nexta >= N || nextb < 0 || nextb >= M)
			continue;
		if (!visited[nexta][nextb]) {
			visited[nexta][nextb] = true;
			DFS(nexta, nextb, cnt + 1, sum + arr[a][b]);
			visited[nexta][nextb] = false;
		}
	}
}

int f1(int a, int b) {
	if (a + 1 >= N || b + 2 >= M) 
		return 0;
	return arr[a][b] + arr[a][b + 1] + arr[a][b + 2] + arr[a + 1][b + 1];
}
int f2(int a, int b) {
	if (a - 1 < 0 || a + 1 >= N || b + 1 >= M)
		return 0;
	return arr[a][b] + arr[a - 1][b + 1] + arr[a][b + 1] + arr[a + 1][b + 1];
}
int f3(int a, int b) {
	if (a - 1 < 0 || b + 2 >= M )
		return 0;
	return arr[a][b] + arr[a][b + 1] + arr[a][b + 2] + arr[a - 1][b + 1];
}
int f4(int a, int b) {
	if ( a + 2 >= N || b + 1 >= M)
		return 0;
	return arr[a][b] + arr[a + 1][b] + arr[a + 2][b] + arr[a + 1][b + 1];
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> arr[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			DFS(i, j, 0, 0);
			visited[i][j] = false;
			int tmp = f1(i, j);
			answer = tmp > answer ? tmp : answer;
			tmp = f2(i, j);
			answer = tmp > answer ? tmp : answer;
			tmp = f3(i, j);
			answer = tmp > answer ? tmp : answer;
			tmp = f4(i, j);
			answer = tmp > answer ? tmp : answer;
		}
	}

	cout << answer << endl;

	return 0;
}