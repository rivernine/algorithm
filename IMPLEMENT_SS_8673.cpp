#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int T, K;
int n1, n2;

int main() {
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		cin >> K;
		vector<int> vc;
		int answer = 0;
		for (int i = 0; i < pow(2, K); i++) {
			cin >> n1;
			vc.push_back(n1);
		}
		
		while (true) {
			if (vc.size() == 1) {
				cout << "#" << testcase + 1 << " " << answer << endl;
				break;
			}
			vector<int> tmpvc;
			for (int i = 0; i < vc.size(); i = i + 2) {
				int winner = vc[i] >= vc[i + 1] ? vc[i] : vc[i + 1];
				answer += abs(vc[i] - vc[i + 1]);
				tmpvc.push_back(winner);
			}
			vc.swap(tmpvc);
		}
	}


	return 0;
}