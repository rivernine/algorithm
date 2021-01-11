#include <iostream>
#include <algorithm>

using namespace std;

int arr[50];
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	if (N == 1)
		cout << arr[0] * arr[0] << endl;
	else
		cout << arr[0] * arr[N-1];
}