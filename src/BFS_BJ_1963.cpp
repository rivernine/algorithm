#include <iostream>
#include <queue>

using namespace std;

int T;
int p1, p2;
int digit[4] = { 1, 10, 100, 1000 };
bool isNotPrime[10000] = { 0 };

struct Status {
	int num, cost;
};

void init() {
	for (int i = 2; i <= 9999; i++) 
		for (int j = 2; i * j <= 9999; j++) 
			isNotPrime[i * j] = true;		
}

int change(int num, int digit, int n) {	
	int tmp = (num / digit) % 10;
	num = num - tmp * digit;
	num = num + n * digit;	
	return num;
}

int BFS(int p1, int p2) {
	bool visited[10000] = { 0 };

	queue<Status> que;
	que.push({ p1, 0 });
	visited[p1] = true;
	while (!que.empty()) {
		Status fnt = que.front();
		que.pop();
		if (fnt.num == p2)
			return fnt.cost;
		//cout << "fnt: " << fnt.num << ", " << fnt.cost << endl;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 9; j++) {
				if (i == 3 && j == 0)
					continue;
				int tmp = change(fnt.num, digit[i], j);
				if (!isNotPrime[tmp] && !visited[tmp]) {
					visited[tmp] = true;
					que.push({ tmp, fnt.cost + 1 });
				}
			}
		}
	}

	return -1;
}

int main() {
	init();

	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		cin >> p1 >> p2;
		int answer = BFS(p1, p2);
		if (answer == -1)
			cout << "impossible" << endl;
		else
			cout << answer << endl;
	}

	return 0;
}