#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, M, A, C, P;
int m, a, b;
int usrMove[2][100];
int ap[8][11][11] = { 0 };
int usr[2][11][11] = { 0 };
int da[5] = { 0, -1, 0, 1, 0 };
int db[5] = { 0, 0, 1, 0, -1 };

struct Ap {
	int a, b, range, power, idx;
};

void initAp() {
	for (int i = 0; i < 8; i++) 
		for (int j = 0; j < 11; j++) 
			for (int k = 0; k < 11; k++) 
				ap[i][j][k] = 0;
}

void setAp(int idx) {
	queue<Ap> que;
	que.push({ b, a, C, -1, -1 });
	ap[idx][b][a] = P;

	while (!que.empty()) {
		Ap fnt = que.front();
		que.pop();
		if (fnt.range == 0)
			continue;

		for (int i = 1; i < 5; i++) {
			int nexta = fnt.a + da[i];
			int nextb = fnt.b + db[i];
			if (nexta < 1 || nexta >= 11 || nextb < 1 || nextb >= 11)
				continue;
			if (ap[idx][nexta][nextb] == 0) {
				que.push({ nexta, nextb, fnt.range - 1, -1, -1 });
				ap[idx][nexta][nextb] = P;
			}
		}
	}
}

int charge(int usr1a, int usr1b, int usr2a, int usr2b) {
	int result = 0;

	vector<Ap> usrAp[2];

	usrAp[0].push_back({ -1, -1, -1, 0, -1 });
	usrAp[1].push_back({ -1, -1, -1, 0, -2 });

	for (int i = 0; i < A; i++) {
		if (ap[i][usr1a][usr1b] != 0) 
			usrAp[0].push_back({ -1, -1, -1, ap[i][usr1a][usr1b], i });
		if (ap[i][usr2a][usr2b] != 0)
			usrAp[1].push_back({ -1, -1, -1, ap[i][usr2a][usr2b], i });
	}
	for (int i = 0; i < usrAp[0].size(); i++) {
		for (int j = 0; j < usrAp[1].size(); j++) {
			/*cout << "usr1 : " << usrAp[0][i].idx << ", " << usrAp[0][i].power << endl;
			cout << "usr2 : " << usrAp[1][i].idx << ", " << usrAp[1][i].power << endl;*/
			int tmp;
			if (usrAp[0][i].idx == usrAp[1][j].idx) {
				tmp = usrAp[0][i].power / 2;
			} else {
				tmp = usrAp[0][i].power + usrAp[1][j].power;
			}
			result = tmp > result ? tmp : result;
		}
	}

	//cout << "result: " << result << endl;
	return result;
}

int main() {
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		cin >> M >> A;
		
		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < M; j++) 
				cin >> usrMove[i][j];
		int usr1a, usr1b, usr2a, usr2b;
		usr1a = usr1b = 1;
		usr2a = usr2b = 10;
		usr[0][usr1a][usr1b] = 1;
		usr[1][usr2a][usr2b] = 1;

		initAp();
		for (int idx = 0; idx < A; idx++) {
			cin >> a >> b >> C >> P;
			setAp(idx);
		}
		int answer = charge(usr1a, usr1b, usr2a, usr2b);
		for (int i = 0; i < M; i++) {
			usr1a += da[usrMove[0][i]];
			usr1b += db[usrMove[0][i]];
			usr2a += da[usrMove[1][i]];
			usr2b += db[usrMove[1][i]];
			answer += charge(usr1a, usr1b, usr2a, usr2b);
		}

		cout << "#" << testcase + 1 << " " << answer << endl;
	}

	return 0;
}