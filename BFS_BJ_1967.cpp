#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
struct Status {
	int node, len;
};
vector<Status> vc[10001];

int BFS(int idx) {
	int result = 0;
	queue<Status> que;
	bool visited[10001] = { 0 };
	que.push({ idx, 0 });
	visited[idx] = true;

	while (!que.empty()) {
		Status fnt = que.front();
		que.pop();

		result = fnt.len > result ? fnt.len : result;

		for (int i = 0; i < vc[fnt.node].size(); i++) {
			Status tmp = vc[fnt.node][i];
			if (!visited[tmp.node]) {
				visited[tmp.node] = true;
				que.push({ tmp.node, fnt.len + tmp.len });
			}
		}
	}

	return result;
}

int main() {
	int answer = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int n1, n2, len;
		cin >> n1 >> n2 >> len;

		vc[n1].push_back({ n2, len });
		vc[n2].push_back({ n1, len });
	}

	for (int i = 1; i <= n; i++) {
		int tmp = BFS(i);
		answer = tmp > answer ? tmp : answer;
	}

	cout << answer << endl;

	return 0;
}