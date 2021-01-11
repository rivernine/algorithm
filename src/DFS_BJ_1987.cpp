#include <iostream>

using namespace std;

int R, C;
char arr[20][20];
bool visited[20][20] = { 0 };
bool alphabet[26] = { 0 };
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1 ,1 };
int answer = 0;

void DFS(int a, int b, int cost) {
	answer = cost > answer ? cost : answer;
	for (int i = 0; i < 4; i++) {
		int tmpa = a + da[i];
		int tmpb = b + db[i];
		if (tmpa < 0 || tmpa >= R || tmpb < 0 || tmpb >= C)
			continue;
		if (!alphabet[arr[tmpa][tmpb] - 65] && !visited[tmpa][tmpb]) {
			alphabet[arr[tmpa][tmpb] - 65] = true;
			visited[tmpa][tmpb] = true;
			DFS(tmpa, tmpb, cost + 1);
			alphabet[arr[tmpa][tmpb] - 65] = false;
			visited[tmpa][tmpb] = false;
		}
	}
}

int main() {
	//int A = 'A'; // 65
	//int Z = 'Z'; // 90

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];

	visited[0][0] = true;
	alphabet[arr[0][0] - 65] = true;
	DFS(0, 0, 1);
	cout << answer << endl;

	return 0;
}