#include <iostream>
#include <queue>

using namespace std;

int N, M;
char arr[10][10];
int da[4] = { -1, 1, 0, 0 };
int db[4] = { 0, 0, -1, 1 };
bool visited[10][10][10][10] = { 0 };

struct Status {
	int ra, rb, ba, bb, cost;
};

void print(Status status) {
	cout << status.cost << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == status.ra && j == status.rb) {
				cout << 'R';
			}
			else if (i == status.ba && j == status.bb) {
				cout << 'B';
			}
			else {
				cout << arr[i][j];

			}
		} cout << endl;
	}
	cout << endl;

}

int main() {
	cin >> N >> M;
	Status init = { 0, 0, 0, 0, 0 };
	queue<Status> que;
	int answer = -1;
	bool findAnswer = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if( arr[i][j] == 'R' ){
				init.ra = i;
				init.rb = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				init.ba = i;
				init.bb = j;
				arr[i][j] = '.';
			}
		}
	}	
	que.push(init);
	visited[init.ra][init.rb][init.ba][init.bb] = true;	
	while (!que.empty()) {
		Status front = que.front();
		que.pop();
		//print(front);

		if (front.cost == 10 || findAnswer)
			break;

		for (int i = 0; i < 4; i++) {
			int tmp_ra = front.ra;	int tmp_rb = front.rb;
			int tmp_ba = front.ba;	int tmp_bb = front.bb;			
			int red_cnt = 0;		int blue_cnt = 0;
			bool redGoal = false;	bool blueGoal = false;

			while (arr[tmp_ra + da[i]][tmp_rb + db[i]] != '#') {
				tmp_ra += da[i];
				tmp_rb += db[i];
				red_cnt++;
				if (arr[tmp_ra][tmp_rb] == 'O') {
					redGoal = true;
					break;
				}
			}
			while (arr[tmp_ba + da[i]][tmp_bb + db[i]] != '#') {				
				tmp_ba += da[i];
				tmp_bb += db[i];
				blue_cnt++;
				if (arr[tmp_ba][tmp_bb] == 'O') {
					blueGoal = true;
					break;
				}
			}

			if (blueGoal)
				continue;
			else if (redGoal) {
				answer = front.cost + 1;
				findAnswer = true;
				break;
			}

			// °ãÄ¥¶§
			if (tmp_ra == tmp_ba && tmp_rb == tmp_bb) {
				if (red_cnt < blue_cnt) {
					tmp_ba -= da[i];
					tmp_bb -= db[i];
				}
				else {
					tmp_ra -= da[i];
					tmp_rb -= db[i];
				}
			}
			if (!visited[tmp_ra][tmp_rb][tmp_ba][tmp_bb]) {
				que.push({ tmp_ra, tmp_rb, tmp_ba, tmp_bb, front.cost + 1 });
				visited[tmp_ra][tmp_rb][tmp_ba][tmp_bb] = true;
			}
		}
	}

	cout << answer << endl;

	return 0;
}