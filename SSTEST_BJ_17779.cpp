#include <iostream>
#include <limits.h>

using namespace std;

int N;
int arr[21][21], tmp[21][21];

void arr2tmp() {
	for (int i = 0; i < 21; i++) 
		for (int j = 0; j < 21; j++) 
			tmp[i][j] = arr[i][j];
}

void makeBorder(int x, int y, int d1, int d2) {
	arr2tmp();
	for (int i = 0; i <= d1; i++)
		tmp[x + i][y - i] = 0;
	for (int i = 0; i <= d2; i++)
		tmp[x + i][y + i] = 0;
	for( int i = 0; i <= d2; i++ )
		tmp[x + d1 + i][y - d1 + i] = 0;
	for (int i = 0; i <= d1; i++)
		tmp[x + d2 + i][y + d2 - i] = 0;

	for (int i = 1; i <= N; i++) {
		bool flag = false;
		if (i == x || i == x + d1 + d2)
			continue;
		for (int j = 1; j <= N; j++) {
			if (tmp[i][j] == 0 && !flag) 
				flag = true;
			else if (tmp[i][j] == 0 && flag) 
				flag = false;
			
			if (flag) 
				tmp[i][j] = 0;			
		}
	}

		
}

int cal(int x, int y, int d1, int d2) {
	int s[6] = { 0 };
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {		
			if (tmp[r][c] == 0) {
				s[5] += arr[r][c];
			} else if (1 <= r && r < x + d1 && 1 <= c && c <= y) {
				s[1] += arr[r][c];
			}
			else if (1 <= r && r <= x + d2 && y < c && c <= N) {
				s[2] += arr[r][c];
			}
			else if (x + d1 <= r && r <= N && 1 <= c && c < y - d1 + d2) {
				s[3] += arr[r][c];
			}
			else if (x + d2 < r && r <= N && y - d1 + d2 <= c && c <= N) {
				s[4] += arr[r][c];
			}
			else {
				s[5] += arr[r][c];
			}
		}
	}

	int maxFood = 0;
	int minFood = INT_MAX;

	for (int i = 1; i <= 5; i++) {
		maxFood = s[i] > maxFood ? s[i] : maxFood;
		minFood = s[i] < minFood ? s[i] : minFood;
	}

	return maxFood - minFood;
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << tmp[i][j] << " ";
		} cout << endl;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	int answer = INT_MAX;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (d1 >= 1 && d2 >= 1 && 1 <= x && x < x + d1 + d2 && x + d1 + d2 <= N) {
						if (1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= N) {
							//cout << "x, y, d1, d2: " << x << ", " << y << ", " << d1 << ", " << d2 << endl;
							makeBorder(x, y, d1, d2);
							int tmp = cal(x, y, d1, d2);
							//print();
							//cout << "tmp: " << tmp << endl;
							//cout << endl;
							answer = tmp < answer ? tmp : answer;
						}
					}
				}
			}
		}
	}

	cout << answer << endl;

	return 0;
}