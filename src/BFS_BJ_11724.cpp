#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1001][1001];
bool visited[1001] = { 0 };

void print() {
	for (int i = 1; i <= N; i++)
		cout << visited[i] << " ";
	cout << endl;
}

int findStart() {
	for (int i = 1; i <= N; i++) {
		if (!visited[i])
			return i;
	}
	return -1;
}

int main() {
	int answer = 0;
	int point;
	queue<int> que;
	cin >> N >> M;		
	for (int i = 0; i < M; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		arr[tmp1][tmp2] = 1;
		arr[tmp2][tmp1] = 1;
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	}*/

	point = findStart();
	visited[point] = true;
	que.push(point);
	answer++;
	while (true) {
		//print();
		if (!que.empty()) {
			int front = que.front();
			//cout << "front: " << front << endl;
			que.pop();
			
			for (int i = 1; i <= N; i++) {
				if (arr[front][i] == 1 && !visited[i]) {		
					//cout << "push: " << i << endl;
					visited[i] = true;
					que.push(i);
				}
			}
		} else {
			point = findStart();
			if (point == -1) 
				break;							
			visited[point] = true;
			que.push(point);
			answer++;
		}
	}
	
	cout << answer << endl;

	return 0;
}