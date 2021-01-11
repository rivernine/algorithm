#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
bool visited[1000001];
struct Status {
	int floor, cost;
};

int main() {
	cin >> F >> S >> G >> U >> D;
	queue<Status> que;
	int answer;
	bool isPossible = false;

	que.push({ S, 0 });
	visited[S] = true;
	while (!que.empty()) {
		Status fnt = que.front();
		que.pop();

		if (fnt.floor == G) {
			isPossible = true;
			answer = fnt.cost;
			break;
		}

		int tmpUp = fnt.floor + U;
		int tmpDown = fnt.floor - D;
		if (tmpUp > 0 && tmpUp <= F ) {
			if (!visited[tmpUp]) {
				visited[tmpUp] = true;
				que.push({ tmpUp, fnt.cost + 1 });
			}
		}
		if (tmpDown > 0 && tmpDown <= F) {
			if (!visited[tmpDown]) {
				visited[tmpDown] = true;
				que.push({ tmpDown, fnt.cost + 1 });
			}
		}
	}

	if (isPossible)
		cout << answer << endl;
	else
		cout << "use the stairs" << endl;

	return 0;
}