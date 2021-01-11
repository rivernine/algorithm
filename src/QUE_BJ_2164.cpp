#include <iostream>
#include <queue>

using namespace std;

//void print(queue<int> que) {
//	while (!que.empty()) {
//		cout << que.front() << " ";
//		que.pop();
//	}
//	cout << endl;
//}

int main() {
	int N;
	queue<int> que;

	cin >> N;
	for (int i = 1; i <= N; i++)
		que.push(i);

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	while (true) {		
		que.pop();
		if (que.size() == 1) {
			cout << que.front() << endl;
			break;
		}
		int front = que.front();
		que.pop();
		que.push(front);
	}

	return 0;
}