#include <iostream>
#include <string>

using namespace std;

int N;
int arr[13];
bool visited[13] = { 0 };

void DFS(int idx, int cnt, string str) {
	if (cnt == 6) {
		cout << str << "\n";
		return;
	}

	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			DFS(i, cnt + 1, str + to_string(arr[i]) + " ");
			visited[i] = false;
		}
	}
}

int main() {	
	while (true) {
		cin >> N;
		if (N == 0)	break;
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		DFS(0, 0, "");
		cout << "\n";
	}


	return 0;
}