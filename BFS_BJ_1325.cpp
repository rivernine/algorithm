#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<int> vc[10001];

struct Status {
	int comp, cost;
};

int BFS(int comp) {
	int result = 0;

	bool visited[10001] = { 0 };
	queue<int> que;
	que.push(comp);
	visited[comp] = true;
	while (!que.empty()) {
		int fnt = que.front();
		que.pop();
		for (int i = 0; i < vc[fnt].size(); i++) {
			int tmp = vc[fnt][i];
			if (!visited[tmp]) {
				visited[tmp] = true;
				que.push(tmp);
				result++;
			}
		}
	}

	return result;
}

int main() {
	vector<int> answer(10001);
	int ansMax = 0;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		vc[c2].push_back(c1);
	}

	for (int i = 1; i <= N; i++) {
		answer[i] = BFS(i);
		ansMax = answer[i] > ansMax ? answer[i] : ansMax;
	}

	for (int i = 1; i <= N; i++) 
		if (answer[i] == ansMax)
			cout << i << " ";
	cout << endl;


	return 0;
}