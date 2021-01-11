#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int N, M;
int arr[101][101] = { 0 };
int copy_arr[101][101];
int answer[101];


void print() {
	cout << "###########" << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << copy_arr[i][j];
		}cout << endl;
	} cout << endl;
}

void copy() {
	for (int i = 0; i <= N; i++) 
		for (int j = 0; j <= N; j++)
			copy_arr[i][j] = arr[i][j];
}

int BFS(int idx) {
	int result = 0;
	copy();
	bool visited[101] = { 0 };
	queue<pair<int,int>> que;
	que.push(make_pair(idx,0));
	visited[idx] = true;
	while (!que.empty()) {
		pair<int,int> front = que.front();
		que.pop();
		//cout << front.first << ", " << front.second << endl;
		for (int i = 1; i <= N; i++) {
			if (copy_arr[front.first][i] >= 1 && !visited[i]) {
				//cout << "push : " << i << ", " << front.second << "+" << arr[front.first][i] << endl;
				que.push(make_pair(i, front.second + copy_arr[front.first][i]));
				visited[i] = true;
				copy_arr[idx][i] = front.second + copy_arr[front.first][i];
				copy_arr[i][idx] = front.second + copy_arr[front.first][i];
			}
		}
	}

	for (int i = 1; i <= N; i++)
		result += copy_arr[idx][i];

	return result;
}

int main() {
	int answer = INT_MAX;
	int answer_idx;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int tmpa, tmpb;
		cin >> tmpa >> tmpb;
		arr[tmpa][tmpb] = 1;
		arr[tmpb][tmpa] = 1;
	}

	for (int i = 1; i <= N; i++) {
		int tmp = BFS(i);
		if (tmp < answer) {
			answer = tmp;
			answer_idx = i;
		}
	}	

	cout << answer_idx << endl;

	return 0;
}