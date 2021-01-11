#include <iostream>
#include <vector>
#include <limits.h>

#define left 0
#define right 1
#define up 2
#define down 3

using namespace std;

struct Status {
	int a, b, camera, dir;
};
int N, M;
int arr[8][8];
int tmp[8][8];
int da[4] = { 0, 0, -1, 1 };
int db[4] = { -1, 1, 0, 0 };
int answer = INT_MAX;
vector<Status> cctv;

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << tmp[i][j] << " ";
		} cout << endl;
	}
}

void see(int a, int b, int dir) {
	int nexta = a;
	int nextb = b;
	while (true) {
		nexta = nexta + da[dir];
		nextb = nextb + db[dir];
		if (nexta < 0 || nexta >= N || nextb < 0 || nextb >= M || arr[nexta][nextb] == 6) {
			return;
		}
		if (arr[nexta][nextb] >= 1 && arr[nexta][nextb] <= 5) {
			continue;
		}
		tmp[nexta][nextb] = 9;
	}
}

void arr2tmp() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp[i][j] = arr[i][j];
}

void start() {
	for (int i = 0; i < cctv.size(); i++) {
		int cura = cctv[i].a;
		int curb = cctv[i].b;
		int curcam = cctv[i].camera;
		int curdir = cctv[i].dir;
		switch (curcam) {
		case 1:
			if (curdir == 0) {
				see(cctv[i].a, cctv[i].b, right);
			} else if (curdir == 1) {
				see(cctv[i].a, cctv[i].b, down);
			} else if (curdir == 2) {
				see(cctv[i].a, cctv[i].b, left);
			} else if (curdir == 3) {
				see(cctv[i].a, cctv[i].b, up);
			}
			break;
		case 2:
			if (curdir == 0) {
				see(cctv[i].a, cctv[i].b, left);
				see(cctv[i].a, cctv[i].b, right);
			} else if (curdir == 1) {
				see(cctv[i].a, cctv[i].b, up);
				see(cctv[i].a, cctv[i].b, down);
			}
			break;
		case 3:
			if (curdir == 0) {
				see(cctv[i].a, cctv[i].b, up);
				see(cctv[i].a, cctv[i].b, right);
			} else if (curdir == 1) {
				see(cctv[i].a, cctv[i].b, right);
				see(cctv[i].a, cctv[i].b, down);
			} else if (curdir == 2) {
				see(cctv[i].a, cctv[i].b, down);
				see(cctv[i].a, cctv[i].b, left);
			} else if (curdir == 3) {
				see(cctv[i].a, cctv[i].b, left);
				see(cctv[i].a, cctv[i].b, up);
			}
			break;
		case 4:
			if (curdir == 0) {
				see(cctv[i].a, cctv[i].b, left);
				see(cctv[i].a, cctv[i].b, up);
				see(cctv[i].a, cctv[i].b, right);
			} else if (curdir == 1) {
				see(cctv[i].a, cctv[i].b, up);
				see(cctv[i].a, cctv[i].b, right);
				see(cctv[i].a, cctv[i].b, down);
			} else if (curdir == 2) {
				see(cctv[i].a, cctv[i].b, right);
				see(cctv[i].a, cctv[i].b, down);
				see(cctv[i].a, cctv[i].b, left);
			} else if (curdir == 3) {
				see(cctv[i].a, cctv[i].b, down);
				see(cctv[i].a, cctv[i].b, left);
				see(cctv[i].a, cctv[i].b, up);
			}
			break;
		case 5:
			see(cctv[i].a, cctv[i].b, right);
			see(cctv[i].a, cctv[i].b, down);
			see(cctv[i].a, cctv[i].b, left);
			see(cctv[i].a, cctv[i].b, up);
			break;
		}
	}
}

int cal() {
	int result = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (tmp[i][j] == 0)
				result++;

	return result;
}

void DFS(int idx) {
	if (idx == cctv.size()) {
		//print();
		arr2tmp();
		start();
		/*cout << endl;
		print();*/
		int tmp = cal();
		answer = tmp < answer ? tmp : answer;
		return;
	}
		
	switch (cctv[idx].camera) {
	case 1:
		for (int i = 0; i < 4; i++) {
			cctv[idx].dir = i;
			DFS(idx + 1);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			cctv[idx].dir = i;
			DFS(idx + 1);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			cctv[idx].dir = i;
			DFS(idx + 1);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			cctv[idx].dir = i;
			DFS(idx + 1);
		}
		break;
	case 5:
		DFS(idx + 1);
		break;
	}
	

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5 ) {
				cctv.push_back({ i, j, arr[i][j], 0 });
			}
		}
	}
	DFS(0);
	cout << answer << endl;
	return 0;
}