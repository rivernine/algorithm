#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int arr[100][100];
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };

int DFS(int a, int b) {
	int result = 1;

	for (int i = 0; i < 4; i++) {
		int tmpa = a + da[i];
		int tmpb = b + db[i];

		if (tmpa < 0 || tmpa >= N || tmpb < 0 || tmpb >= M)
			continue;
		if (arr[tmpa][tmpb] == 0) {
			arr[tmpa][tmpb] = 1;
			result += DFS(tmpa, tmpb);
		}
	}

	return result;
}

int main() {
	vector<int> answer;

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int n = b; n < d; n++) {
			for (int m = a; m < c; m++) {
				arr[n][m] = 1;
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				answer.push_back(DFS(i, j));
			}
		} 
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}