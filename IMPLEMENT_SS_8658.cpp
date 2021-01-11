#include <iostream>

using namespace std;

int T;
int arr[10];

int sol(int n) {
	if (n < 10)
		return n;
	return n % 10 + sol(n / 10);
}

int main() {
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		int max = 0;
		int min = 10000000;

		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
			int tmp = sol(arr[i]);
			max = tmp > max ? tmp : max;
			min = tmp < min ? tmp : min;			
		}

		cout << "#" << testcase + 1 << " " << max << " " << min << endl;
	}


	return 0;
}