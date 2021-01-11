#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int N, K, a, b, L, X;
char C;
int arr[100][100] = { 0 };
int da[4] = { 0, 1, 0, -1 };
int db[4] = { 1, 0, -1, 0 };
int turnL[4] = { 3, 0, 1, 2 };
int turnR[4] = { 1, 2, 3, 0 };

struct Info {
	int time, turn;
};
struct Status {
	int a, b;
};
struct Head {
	int a, b, dir;
};

void print() {
	cout << "#########################" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		} cout << endl;
	}

}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		arr[a - 1][b - 1] = 2;
	}
	cin >> L;
	queue<Info> que;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		que.push({ X, C });
	}

	int answer = 0;
	deque<Status> dque;
	Head head = { 0, 0, 0 };
	dque.push_front({ 0, 0 });
	arr[0][0] = 1;

	while (true) {
		bool isEnd = false;
		Info fnt;
		if (!que.empty()) {
			fnt = que.front();
			que.pop();
			fnt.time -= answer;
		} else {
			fnt.turn = head.dir;
			fnt.time = 100;
		}
		
		//cout << "fnt: " << fnt.time << ", " << char(fnt.turn) << endl;
		for (int i = 0; i < fnt.time; i++) {
			//cout << "head: " << head.a << ", " << head.b << ", " << head.dir << endl;
			Status next = { head.a + da[head.dir], head.b + db[head.dir] };
			answer++;
			if (next.a < 0 || next.a >= N || next.b < 0 || next.b >= N) {
				isEnd = true;
				break;
			} else if (arr[next.a][next.b] == 1) {
				isEnd = true;
				break;
			} else if (arr[next.a][next.b] == 2) {
				arr[next.a][next.b] = 1;
				dque.push_front({ next.a, next.b });
			} else if (arr[next.a][next.b] == 0) {
				arr[next.a][next.b] = 1;
				dque.push_front({ next.a, next.b });
				Status tmp = dque.back();
				dque.pop_back();
				arr[tmp.a][tmp.b] = 0;
			}
			head.a = next.a;
			head.b = next.b;
		};
		if (fnt.turn == 'L') {
			head.dir = turnL[head.dir];
		} else if (fnt.turn == 'D') {
			head.dir = turnR[head.dir];
		}
		if (isEnd) {
			cout << answer << endl;
			break;
		}
	}

	return 0;
}