#include <iostream>
#include <queue>

using namespace std;

int R, C, T;
int arr[50][50], tmp[50][50];
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1 ,1 };
int ca[2][4] = { -1, 0, 1, 0,
				 1, 0, -1, 0 };
int cb[2][4] = { 0, 1, 0, -1,
				 0, 1, 0, -1 };
int height[2][2];

void arr2tmp() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			tmp[i][j] = arr[i][j];
}
void tmp2arr() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			arr[i][j] = tmp[i][j];
}
void print() {
	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	}
}


void spread() {
	arr2tmp();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] > 0) {
				int tmpSum = 0;
				for (int k = 0; k < 4; k++) {
					int nexta = i + da[k];
					int nextb = j + db[k];
					if (nexta < 0 || nexta >= R || nextb < 0 || nextb >= C || tmp[nexta][nextb] == -1)
						continue;
					tmp[nexta][nextb] += arr[i][j] / 5;
					tmpSum += arr[i][j] / 5;
				}
				tmp[i][j] -= tmpSum;
			}
		}
	}
	tmp2arr();
}

void care(int idx, int a, int b) {
	queue<pair<int, int>> que;
	int dir = 0;
	que.push({ a + ca[idx][dir], b + cb[idx][dir] });	
	while (!que.empty()) {
		pair<int, int> cur = que.front();
		//cout << "cur: " << cur.first << ", " << cur.second << endl;
		que.pop();
		int nexta = cur.first + ca[idx][dir];
		int nextb = cur.second + cb[idx][dir];
		if (arr[nexta][nextb] == -1) {
			arr[cur.first][cur.second] = 0;
			break;
		}
			
		if (nexta < height[idx][0] || nexta > height[idx][1] || nextb < 0 || nextb >= C) {
			dir++;
			nexta = cur.first + ca[idx][dir];
			nextb = cur.second + cb[idx][dir];
		}
		arr[cur.first][cur.second] = arr[nexta][nextb];
		que.push({ nexta, nextb });
	}
}

int cal() {
	int result = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != 0 && arr[i][j] != -1) {
				result += arr[i][j];
			}
		}
	}
	return result;
}

int main() {
	cin >> R >> C >> T;
	pair<int, int> puri[2] = { {-1, -1}, {-1, -1} };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (puri[0].first == -1) {
					puri[0] = { i, j };
					height[0][0] = 0;
					height[0][1] = i;
				} else {
					puri[1] = { i, j };
					height[1][0] = i;
					height[1][1] = R - 1;
				}
			}
		}
	}

	for (int i = 0; i < T; i++) {
		spread();
		care( 0, puri[0].first, puri[0].second );
		care( 1, puri[1].first, puri[1].second );
	}

	cout << cal() << endl;

	return 0;
}