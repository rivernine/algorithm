#include <iostream>
#include <vector>
using namespace std;

long long N, B, C;
long long tmp;
vector<long long> vc;

int main() {
	long long answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vc.push_back(tmp);
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		vc[i] -= B;
		answer++;
		if (vc[i] <= 0)
			continue;
		answer += vc[i] / C;
		if (vc[i] % C != 0)
			answer++;
	}
	cout << answer << endl;

	return 0;
}