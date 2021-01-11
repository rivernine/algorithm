#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> tree[10][10];
int ground[10][10], robot[10][10];
int dead[10][10];
int da[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int db[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void printTree() {
	cout << "Tree" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tree[i][j].size()) {
				cout << "i, j: " << i << ", " << j << endl;
				for (int k = 0; k < tree[i][j].size(); k++) {
					cout << tree[i][j][k] << " ";
				} cout << endl;
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ground[i][j] += robot[i][j];
		}
	}
}

void fall() {
	int breed[10][10] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5 == 0) {
					for (int m = 0; m < 8; m++) {
						int nexta = i + da[m];
						int nextb = j + db[m];
						if (nexta < 0 || nexta >= N || nextb < 0 || nextb >= N)
							continue;
						breed[nexta][nextb]++;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < breed[i][j]; k++) {
				tree[i][j].push_back(1);
			}
		}
	}
}

void summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ground[i][j] += dead[i][j];
		}
	}
}

void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sort(tree[i][j].begin(), tree[i][j].end());
			dead[i][j] = 0;
			int tmpSize = tree[i][j].size();
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (ground[i][j] >= tree[i][j][k]) {
					ground[i][j] -= tree[i][j][k];
					tree[i][j][k]++;
				} else {
					dead[i][j] += (tree[i][j][k] / 2);
					tree[i][j].erase(tree[i][j].begin() + k);
					k--;
				}
			}
		}
	}
}

int cal() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result += tree[i][j].size();
		}
	}

	return result;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> robot[i][j];
			ground[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		tree[t1 - 1][t2 - 1].push_back(t3);
	}
	//printTree();
	for (int i = 0; i < K; i++) {		
		spring();
		summer();
		fall();
		winter();
		//printTree();
	}

	cout << cal() << endl;

	return 0;
}