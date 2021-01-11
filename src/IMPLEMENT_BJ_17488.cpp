#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, tmp;
int sub[1000];
vector<int> vc[1000];
vector<int> usr[1000];

void comp(int idx) {
	for (int i = 0; i < vc[idx].size(); i++) {
		usr[vc[idx][i]].push_back(idx);
	}
}


void chk() {
	for (int i = 0; i < M; i++) {
		if (vc[i].size() <= sub[i]) {
			comp(i);
			sub[i] = sub[i] - vc[i].size();
			vector<int> tmp;
			vc[i].swap(tmp);
		}
	}
}

void print( int idx ) {
	sort(usr[idx].begin(), usr[idx].end());
	if (usr[idx].size() == 0) {
		cout << "망했어요" << endl;
		return;
	}
	for (int i = 0; i < usr[idx].size(); i++) {
		cout << usr[idx][i] + 1 << " ";
	} cout << endl;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> sub[i];
	}

	// 1차
	for (int i = 0; i < N; i++) {
		while (true) {
			cin >> tmp;
			if (tmp == -1) break;
			vc[tmp - 1].push_back(i);
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < vc[i].size(); j++) {
			cout << vc[i][j] << " ";
		} cout << endl;
	}*/

	chk();
	// 2차
	for (int i = 0; i < N; i++) {
		while (true) {
			cin >> tmp;
			if (tmp == -1) break;
			vc[tmp - 1].push_back(i);
		}
	}
	chk();

	for (int i = 0; i < N; i++) {
		print(i);
	}


	return 0;
}