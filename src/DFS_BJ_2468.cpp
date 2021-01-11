#include <iostream>

using namespace std;

int N;
int min_h = 101;
int max_h = 0;
int arr[100][100];
bool visited[100][100];
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };

void DFS(int a, int b, int k) {
	for (int i = 0; i < 4; i++) {
		int tmpa = a + da[i];
		int tmpb = b + db[i];

		if (tmpa < 0 || tmpa >= N || tmpb < 0 || tmpb >= N)
			continue;
		if (arr[tmpa][tmpb] > k && !visited[tmpa][tmpb]) {
			visited[tmpa][tmpb] = 1;
			DFS(tmpa, tmpb, k);
		}
	}
}

void initVisited() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;	
}

int main() {
	int answer = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] < min_h)
				min_h = arr[i][j];
			if (arr[i][j] > max_h)
				max_h = arr[i][j];
		}
	}

	for (int k = min_h - 1 ; k <= max_h; k++) {
		int tmpAnswer = 0;
		initVisited();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] > k && !visited[i][j] ) {
					visited[i][j] = 1;
					DFS(i, j, k);
					tmpAnswer++;
				}
			}
		}

		if (tmpAnswer > answer)
			answer = tmpAnswer;

	}

	cout << answer << endl;

	return 0;
}