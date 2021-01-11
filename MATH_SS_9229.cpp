#include <iostream>

using namespace std;

int T, N, M;
int arr[1000];

int main() {
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		cin >> N >> M;
		int answer = -1;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				int sum = arr[i] + arr[j];
				answer = (sum > answer && sum <= M) ? sum : answer;
			}
		}

		cout << "#" << testcase + 1 << " " << answer << endl;

	}

	return 0;
}