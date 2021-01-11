#include <iostream>
#include <queue>

using namespace std;

int N, M, r, c, d;
int arr[50][50];
int da[4] = { -1, 0, 1, 0 };
int db[4] = { 0, 1, 0, -1 };
int rot[4] = { 3, 0, 1, 2 };
int back[4] = { 2, 3, 0, 1 };

struct Status {
	int a, b, dir;
};

void print() {
	cout << "###########################" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	}

}

int main() {
	int answer = 0;
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	Status start = { r, c, d };
	queue<Status> que;
	que.push(start);
	while (!que.empty()) {
		Status cur = que.front();
		que.pop();
		
		/*cout << "a, b, dir: " << cur.a << ", " << cur.b << ", " << cur.dir << endl;
		print();*/

		if (arr[cur.a][cur.b] == 0) {
			arr[cur.a][cur.b] = 2;
			answer++;
		}

		bool move = false;
		int nextDir = cur.dir;
		for (int i = 0; i < 4; i++) {
			nextDir = rot[nextDir]; // 다음 방향
			Status next = { cur.a + da[nextDir], cur.b + db[nextDir], nextDir };

			if (next.a < 0 || next.a >= N || next.b < 0 || next.b >= M) 
				continue;
			if (arr[next.a][next.b] == 0) {
				que.push(next);
				move = true;
				break;
			}
		}

		if (!move) {
			Status next = { cur.a + da[back[nextDir]], cur.b + db[back[nextDir]], nextDir };
			if (!(next.a < 0 || next.a >= N || next.b < 0 || next.b >= M)) {
				if( arr[next.a][next.b] == 2)
					que.push(next);
			}
				
		}
	}

	cout << answer << endl;

	return 0;
}