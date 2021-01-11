#include <iostream>
#include <vector>

using namespace std;

int N;
int da[4] = { 1, 0, -1, 0 };
int db[4] = { 0, -1, 0, 1 };
vector<pair<int, int>> vc[20];
bool arr[101][101][20] = { 0 };

void generation(int n, int sx, int sy, int ex, int ey, int cnt) {
	if (cnt == 0)
		return;
	int tmp = vc[n].size();
	int nextex, nextey;
	for (int i = 0; i < tmp; i++) {
		int cx = vc[n][i].first;
		int cy = vc[n][i].second;
		// curve
		int curvx = (cy - ey) * -1 + ex;
		int curvy = cx - ex + ey ;
		if (curvx < 0 || curvx > 100 || curvy < 0 || curvy > 100)
			continue;
		if (!arr[curvx][curvy][n]) {
			vc[n].push_back({ curvx , curvy });
			arr[curvx][curvy][n] = true;
		}
		if ( cx == sx && cy == sy ) {
			nextex = curvx;
			nextey = curvy;
		}
	}
	generation(n, sx, sy, nextex, nextey, cnt - 1);
}

int main() {
	cin >> N;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int a, b, dir, gene;
		cin >> a >> b >> dir >> gene;
		vc[i].push_back({ a, b });
		vc[i].push_back({ vc[i][0].first + da[dir], vc[i][0].second + db[dir] });
		arr[a][b][i] = true;
		arr[vc[i][0].first + da[dir]][vc[i][0].second + db[dir]][i] = true;
		generation(i, vc[i][0].first, vc[i][0].second, vc[i][1].first, vc[i][1].second, gene);		
	}

	bool answerArr[101][101] = { 0 };
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 20; k++) {
				if (arr[i][j][k])
					answerArr[i][j] = true;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (answerArr[j][i] && answerArr[j + 1][i] && answerArr[j][i + 1] && answerArr[j + 1][i + 1])
				answer++;
		}
	}

	cout << answer << endl;
	/*for (int i = 0; i < N; i++) {
		cout << "i: " << i << endl;
		for (int j = 0; j < vc[i].size(); j++) {
			cout << vc[i][j].first << ", " << vc[i][j].second << endl;
		}
	}*/

	return 0;
}