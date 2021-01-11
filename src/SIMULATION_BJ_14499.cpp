#include <iostream>

using namespace std;

int N, M, x, y, K, k;
int arr[20][20];
int dice[4][3] = { 0, 0, 0,
				   0, 0, 0,
				   0, 0, 0,
				   0, 0, 0 };
int copyDice[4][3];
int da[5] = { 0, 0, 0, -1, 1};
int db[5] = { 0, 1, -1, 0, 0};

struct Plane {
	int a, b;
};
Plane _up = { 1, 1 };
Plane _down = { 3, 1 };
Plane _front = { 2, 1 };
Plane _back = { 0, 1 };
Plane _left = { 1, 0 };
Plane _right = { 1, 2 };

void print() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << dice[i][j] << " ";
		} cout << endl;
	}
}

void _swap(Plane from, Plane to) {
	dice[to.a][to.b] = copyDice[from.a][from.b];
}

void _copy() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			copyDice[i][j] = dice[i][j];
}

void rot(int k) {
	switch (k) {
	case 1:
		_copy();
		_swap(_left, _up);
		_swap(_up, _right);
		_swap(_right, _down);
		_swap(_down, _left);
		break;
	case 2:
		_copy();
		_swap(_right, _up);
		_swap(_up, _left);
		_swap(_left, _down);
		_swap(_down, _right);
		break;
	case 3:
		_copy();
		_swap(_up, _back);
		_swap(_back, _down);
		_swap(_down, _front);
		_swap(_front, _up);
		break;
	case 4:
		_copy();
		_swap(_up, _front);
		_swap(_front, _down);
		_swap(_down, _back);
		_swap(_back, _up);
		break;
	}
}

void comp(int a, int b) {
	if (arr[a][b] == 0) {
		arr[a][b] = dice[_down.a][_down.b];
	} else {
		dice[_down.a][_down.b] = arr[a][b];
		arr[a][b] = 0;
	}
}

int main() {
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> k;
		int nexta = x + da[k];
		int nextb = y + db[k];
		if (nexta < 0 || nexta >= N || nextb < 0 || nextb >= M)
			continue;

		rot(k);
		comp(nexta, nextb);
		cout << dice[_up.a][_up.b] << endl;
		x = nexta;
		y = nextb;
	}


	return 0;
}