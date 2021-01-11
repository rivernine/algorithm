#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char arr[12][6];
bool visited[12][6] = { 0 };

int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };
struct Status {
	int a, b;
};

void print() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j];
		} cout << endl;
	}
}

void initVisited() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			visited[i][j] = 0;
}

void down() {
	vector<char> vc[6];

	for (int i = 0; i < 6; i++) {
		for (int j = 11; j >= 0; j--) {
			if( arr[j][i] != 'x')
				vc[i].push_back(arr[j][i]);
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 11; j >= 0; j--) {
			if (vc[i].size() > 0) {
				arr[j][i] = vc[i].front();
				vc[i].erase(vc[i].begin(), vc[i].begin() + 1);
			}
			else {
				arr[j][i] = '.';
			}
		}
	}

}

bool BFS(int a, int b){
	queue<Status> que;
	vector<Status> vcLog;

	que.push({ a, b });
	visited[a][b] = true;

	while (!que.empty()) {
		Status fnt = que.front();
		que.pop();
		vcLog.push_back({ fnt.a, fnt.b });

		for (int i = 0; i < 4; i++) {
			int tmpa = fnt.a + da[i];
			int tmpb = fnt.b + db[i];
			if (tmpa < 0 || tmpa >= 12 || tmpb < 0 || tmpb >= 6)
				continue;
			if (arr[tmpa][tmpb] == arr[fnt.a][fnt.b] && !visited[tmpa][tmpb]) {
				visited[tmpa][tmpb] = true;
				que.push({ tmpa, tmpb });
			}
		}
	}

	if (vcLog.size() >= 4) {
		for (int i = 0; i < vcLog.size(); i++) 
			arr[vcLog[i].a][vcLog[i].b] = 'x';
		return true;
	}
	return false;
}

int puyo() {
	int result = 0;

	while (true) {
		//print();
		initVisited();
		bool isChange = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.' && !visited[i][j]) {
					bool tmp = BFS(i, j);
					if (tmp)
						isChange = true;
				}
			}
		}
		if (isChange) {
			down();
			result++;
		}
		else {
			break;
		}
	}

	return result;
}

int main() {
	for (int i = 0; i < 12; i++) 
		for (int j = 0; j < 6; j++) 
			cin >> arr[i][j];
	
	cout << puyo() << endl;
	

	return 0;
}