#include <iostream>

using namespace std;

int N;
char arr[100][100];
bool visited[100][100][2] = { 0 };
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };

void DFS(int a, int b, char color, bool flag) {
	for (int i = 0; i < 4; i++) {
		int tmpa = a + da[i];
		int tmpb = b + db[i];
		if (tmpa < 0 || tmpa >= N || tmpb < 0 || tmpb >= N)
			continue;
		if (!flag) {
			if (arr[tmpa][tmpb] == color && !visited[tmpa][tmpb][flag]) {
				visited[tmpa][tmpb][flag] = true;
				DFS(tmpa, tmpb, color, flag);
			}
		} else {
			if ((abs(color - arr[tmpa][tmpb]) == 0 || abs(color - arr[tmpa][tmpb]) == 11) && !visited[tmpa][tmpb][flag]) {
				visited[tmpa][tmpb][flag] = true;
				DFS(tmpa, tmpb, color, flag);
			}
		}
	}
}

int main() {
	int ans1 = 0;
	int ans2 = 0;


	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> arr[i][j];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j][0]) {
				ans1++;
				DFS(i, j, arr[i][j], 0);
			}
			if (!visited[i][j][1]) {
				ans2++;
				DFS(i, j, arr[i][j], 1);
			}
		}
	}

	cout << ans1 << " " << ans2 << endl;

	return 0;
}