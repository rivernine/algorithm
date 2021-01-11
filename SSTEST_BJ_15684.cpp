#include <iostream>

using namespace std;

int N, M, H;
int arr[31][11] = { 0 };
int answer = -1;

void print() {
	cout << endl;
	for (int i = 0; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	}
}

int go() {
	for (int i = 1; i <= N; i++) {
		int a = 0;
		int b = i;
		while (a != H) {
			if (b - 1 >= 1) {
				if (arr[a + 1][b - 1] == 1) {
					a = a + 1;
					b = b - 1;
					continue;
				}
			}
			if (arr[a + 1][b] == 1) {
				a = a + 1;
				b = b + 1;
				continue;
			}

			a = a + 1;
			b = b;
		}

		if (i != b)
			return -1;
	}
	return 0;
}

void addLine(int cnt) {
	//print();
	if (go() != -1) {
		answer = cnt;
		return;
	}

	if (cnt == 3 || answer != -1) {
		return;
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (j - 1 >= 1) {
				if (arr[i][j - 1] == 1)
					continue;
			}
			if (j + 1 < N) {
				if (arr[i][j + 1] == 1)
					continue;
			}
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				addLine(cnt + 1);
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	
	addLine(0);
	cout << answer << endl;

	return 0;
}