#include <iostream>
#include <queue>

using namespace std;

int N;
bool arr[101][101];
bool visited[101] = { 0 };

int main() {
	int answer = -1;
	int start, end, m;
	queue<pair<int,int>> que;
	cin >> N >> start >> end >> m;
	for (int i = 0; i < m; i++) {
		int tmpa, tmpb;
		cin >> tmpa >> tmpb;
		arr[tmpa][tmpb] = 1;
		arr[tmpb][tmpa] = 1;
	}

	que.push(make_pair(start, 0));
	visited[start] = true;

	while (!que.empty()) {
		pair<int, int> front = que.front();
		que.pop();

		if (front.first == end) {
			answer = front.second;
			break;
		}
		for (int i = 1; i <= N; i++) {
			if (arr[front.first][i] == 1 && !visited[i]) {
				visited[i] = true;
				que.push(make_pair(i, front.second + 1));
			}
		}
	}

	cout << answer << endl;

	return 0;
}