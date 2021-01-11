#include <iostream>
#include <deque>

using namespace std;
int work[4][2] = { 0 };
int K;
deque<int> dque[4];

void leftchk(int n, int dir) {
	if (n - 1 >= 0) {
		if (dque[n - 1][2] != dque[n][6]) {
			work[n - 1][0] = 1;
			work[n - 1][1] = dir * -1;
			leftchk(n - 1, dir * -1);
		}
	}
}
void rightchk(int n, int dir) {
	if (n + 1 < 4) {
		if (dque[n + 1][6] != dque[n][2]) {
			work[n + 1][0] = 1;
			work[n + 1][1] = dir * -1;
			rightchk(n + 1, dir * -1);
		}
	}
}

void rot(int idx, int dir) {
	if (dir == 1) {
		int tmp = dque[idx].back();
		dque[idx].push_front(tmp);
		dque[idx].pop_back();
	} else {
		int tmp = dque[idx].front();
		dque[idx].push_back(tmp);
		dque[idx].pop_front();
	}
}

int cal() {
	return dque[0].front() * 1 + dque[1].front() * 2 + dque[2].front() * 4 + dque[3].front() * 8;
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int tmp;
			scanf_s("%1d", &tmp);
			dque[i].push_back(tmp);
		}
	}
	scanf_s("%d", &K);
	for (int i = 0; i < K; i++) {
		int t, dir;
		scanf_s("%d %d", &t, &dir);		

		for (int i = 0; i < 4; i++) {
			work[i][0] = 0;
			work[i][1] = 0;
		}
		work[t - 1][0] = 1;
		work[t - 1][1] = dir;
		leftchk(t - 1, dir);
		rightchk(t - 1, dir);
		
		for (int i = 0; i < 4; i++) 
			if (work[i][0]) 
				rot(i, work[i][1]);
	}
	printf("%d\n", cal());

	return 0;
}