#include <iostream>

using namespace std;

int N, K, W, V;
int dp[100001];

int main() {
	cin >> N >> K;
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		for (int j = K; j >= 1; j--) {
			if( W <= j )
				dp[j] = dp[j - W] + V > dp[j] ? dp[j - W] + V : dp[j];
		}		
	}

	cout << dp[K] << endl;

	return 0;
}