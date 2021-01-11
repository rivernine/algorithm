#include <iostream>
#include <queue>
#include <string>

using namespace std;

int T, A, B;
struct Status {
	int num;
	string str;
};


void BFS(int A, int B) {
	bool visited[10000] = { 0 };
	queue<Status> que;
	que.push({ A, "" });
	visited[A] = true;
	while (!que.empty()) {
		Status fnt = que.front();
		que.pop();

		if (fnt.num == B) {
			cout << fnt.str << endl;
			break;
		}

		// D
		int D = fnt.num * 2 % 10000;
		if (!visited[D]) {
			visited[D] = true;
			que.push({ D, fnt.str + "D" });
		}
		// S
		int S = (fnt.num == 0 ? 9999 : fnt.num - 1 );
		if (!visited[S]) {
			visited[S] = true;
			que.push({ S, fnt.str + "S" });
		}
		// L
		int left = fnt.num / 1000;
		int noLeft = fnt.num - (left * 1000);
		int L = noLeft * 10 + left;
		if (!visited[L]) {
			visited[L] = true;
			que.push({ L, fnt.str + "L" });
		}

		// R
		int right = fnt.num % 10;
		int noRight = (fnt.num - right) / 10;
		int R = noRight + right * 1000;
		if (!visited[R]) {
			visited[R] = true;
			que.push({ R, fnt.str + "R" });
		}
	}
}

int main() {
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		cin >> A >> B;
		BFS(A, B);
	}

	return 0;
}