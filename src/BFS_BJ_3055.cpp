#include <iostream>
#include <queue>

using namespace std;

struct Pos {
	int a, b;
};
int R, C;
char arr[50][50];
bool visited[2][50][50];
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };

bool go(queue<Pos> que, int idx) {
	while (!que.empty()) {
		Pos fnt = que.front();
		char symb = arr[fnt.a][fnt.b];
		que.pop();
		visited[idx][fnt.a][fnt.b] = true;

		for (int i = 0; i < 4; i++) {
			int tmpa = fnt.a + da[i];
			int tmpb = fnt.b + db[i];

			if (tmpa < 0 || tmpa >= R || tmpb < 0 || tmpb >= C)
				continue;

			if (symb == 'S') {
				if (arr[tmpa][tmpb] == '.' && !visited[idx][tmpa][tmpb]) {
					arr[tmpa][tmpb] = 'S';
				}
				else if (arr[tmpa][tmpb] == 'D') {
					return true;
				}
			}
			else if (symb == '*') {
				if ((arr[tmpa][tmpb] == '.' || arr[tmpa][tmpb] == 'S') && !visited[idx][tmpa][tmpb]) {
					arr[tmpa][tmpb] = '*';
				}
			}

		}
	}
	return false;
}

int main() {
	int answer = 0;
	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];			

	bool isEnd = false;

	while (true) {
		queue<Pos> runQ, floodQ;
		bool canMove = false;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (!visited[0][i][j] && arr[i][j] == 'S') {
					canMove = true;
					runQ.push({ i, j });
				}
				else if (!visited[1][i][j] && arr[i][j] == '*') {
					floodQ.push({ i, j });
				}
			}
		}
		isEnd = go(runQ, 0);
		go(floodQ, 1);
		answer++;

		if ( !canMove || isEnd )
			break;
	}
	if (isEnd)
		cout << answer << endl;
	else
		cout << "KAKTUS" << endl;

	return 0;
}