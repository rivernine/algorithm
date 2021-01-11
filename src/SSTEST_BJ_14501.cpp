#include <iostream>
#include <vector>

using namespace std;

int N;
bool work[16] = { 0 };
bool doing[21] = { 0 };
vector<pair<int, int>> job;
int answer = 0;

void print() {
	for (int i = 1; i <= N; i++) {
		cout << work[i] << " ";
	} cout << endl;
}

int chk() {
	int result = 0;

	for (int i = 0; i < 21; i++)
		doing[i] = false;

	for (int i = 1; i <= N; i++) {
		if (work[i]) {
			result += job[i].second;
			for (int j = i; j < i + job[i].first; j++) {
				if (!doing[j] && j <= N ) {
					doing[j] = true;
				} else {
					return -1;
				}
			}
		}
	}
	return result;
}

void DFS(int n, int idx) {
	if (n < 0) {
		return;
	}
	
	//print();
	int tmp = chk();
	//cout << "tmp: " << tmp << endl;
	answer = tmp > answer ? tmp : answer;

	for (int i = idx; i <= N; i++) {
		if (!work[i]) {
			work[i] = true;
			DFS(n - 1, i);
			work[i] = false;
		}
	}
}

int main() {
	cin >> N;
	job.push_back({ 0, 0 });
	for (int i = 0; i < N; i++) {
		int t, p;
		cin >> t >> p;
		job.push_back({ t, p });
	}
	DFS(N, 1);
	cout << answer << endl;
}