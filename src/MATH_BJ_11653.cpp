#include <iostream>
#include <vector>

using namespace std;

int N, tmp = 1;

int main() {
	cin >> N;

	while (N != 1) {
		for (int i = 2; i <= N; i++) {
			if (N % i == 0) {
				tmp *= i;
				N = N / i;
				cout << i << endl;
				break;
			}				
		}
	}


	return 0;
}