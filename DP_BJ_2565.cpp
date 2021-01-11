#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;


int main() {
	vector<pair<int, int>> input;
	vector<int> vc, dp(101);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		input.push_back({ n1, n2 });
	}
	sort(input.begin(), input.end());

	vc.push_back(0);
	for (int i = 0; i < N; i++) 
		vc.push_back(input[i].second);
	
	int result = 0;
	for (int i = 1; i < vc.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (vc[i] > vc[j]) {
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
				result = result > dp[i] ? result : dp[i];
			}
		}
	}

	cout << N - result << endl;

	return 0;
}