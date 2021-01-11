#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

struct Shark {
	int a, b, size, cnt;
};
struct Status {
	int a, b, time;
};
int N;
int arr[20][20];
bool visited[20][20] = { 0 };
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };
Shark shark;
queue<Status> start;

void initVisited() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
}

Status BFS(int a, int b) {
	Status result = { 0, 0, 0 };
	queue<Status> que;
	vector<pair<int, int>> food;
	int dist = INT_MAX;
	que.push({ a, b, 0 });
	while (!que.empty()) {
		Status cur = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nexta = cur.a + da[i];
			int nextb = cur.b + db[i];
			if (nexta < 0 || nexta >= N || nextb < 0 || nextb >= N)
				continue;
			if (!visited[nexta][nextb] && cur.time + 1 <= dist) {
				if (arr[nexta][nextb] == 0 || arr[nexta][nextb] == shark.size) {
					visited[nexta][nextb] = true;
					que.push({ nexta, nextb, cur.time + 1 });
				}
				else if (arr[nexta][nextb] != 0 && arr[nexta][nextb] < shark.size) {
					visited[nexta][nextb] = true;
					food.push_back({ nexta, nextb });
					dist = cur.time + 1;
				}
			}
		}
	}
	if (food.size() != 0) {
		sort(food.begin(), food.end());
		result.a = food[0].first;
		result.b = food[0].second;
		result.time = dist;
	} 
	return result;
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				shark = { i, j, 2, 0 };
				start.push({ i, j, 0 });
				arr[i][j] = 0;
			}
		}
	}
	while (!start.empty()) {
		Status cur = start.front();
		start.pop();
		initVisited();
		visited[cur.a][cur.b] = true;
		arr[cur.a][cur.b] = 0;
		Status next = BFS(cur.a, cur.b);
		if (next.time != 0) {
			if (shark.cnt + 1 == shark.size) {
				shark.cnt = 0;
				shark.size++;
			} else {
				shark.cnt++;
			}
			start.push({ next.a, next.b, cur.time + next.time });
		} else {
			cout << cur.time << endl;
		}
	}



	return 0;
}