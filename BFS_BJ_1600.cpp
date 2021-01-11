#include <iostream>
#include <queue>

using namespace std;

int K, W, H;
bool arr[200][200];
bool visited[30][200][200] = { 0 };
int da[12] = { -1, 1, 0, 0, -1, -2, -2, -1, 1, 2, 2, 1 };
int db[12] = { 0, 0, -1, 1, -2, -1, 1, 2, 2, 1, -1, -2 };

struct Status {
	int a, b, horse, cost;
};

int BFS(int a, int b) {
	queue<Status> que;
	que.push({ a, b, K, 0 });
	visited[K][a][b] = true;

	while (!que.empty()) {
		Status fnt = que.front();
		que.pop();

		//cout << "a, b, horse, cost: " << fnt.a << ", " << fnt.b << ", " << fnt.horse << ", " << fnt.cost << endl;

		int move = fnt.horse > 0 ? 12 : 4;
		if (fnt.a == H - 1 && fnt.b == W - 1) 
			return fnt.cost;		

		for (int i = 0; i < move; i++) {
			int tmpa = fnt.a + da[i];
			int tmpb = fnt.b + db[i];
			if (tmpa < 0 || tmpa >= H || tmpb < 0 || tmpb >= W)
				continue;
			if (i < 4) {
				if (!arr[tmpa][tmpb] && !visited[fnt.horse][tmpa][tmpb]) {
					que.push({ tmpa, tmpb, fnt.horse, fnt.cost + 1 });
					visited[fnt.horse][tmpa][tmpb] = true;
					//cout << "push " << tmpa << ", " << tmpb << ", " << fnt.horse << ", " << fnt.cost + 1 << endl;
				}
			}
			else {
				if (!arr[tmpa][tmpb] && !visited[fnt.horse - 1][tmpa][tmpb]) {
					que.push({ tmpa, tmpb, fnt.horse - 1, fnt.cost + 1 });
					visited[fnt.horse - 1][tmpa][tmpb] = true;
					//cout << "push " << tmpa << ", " << tmpb << ", " << fnt.horse - 1 << ", " << fnt.cost + 1 << endl;
				}
			}
		}
	}

	return -1;
}

int main() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
		}
	}

	cout << BFS(0, 0) << endl;

	return 0;
}