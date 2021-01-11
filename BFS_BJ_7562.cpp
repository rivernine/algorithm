#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[300][300];
int da[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int db[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

struct Knite {
	int a;
	int b;
	int count;
};

int main() {
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		queue<Knite> que;
		int sa, sb, ea, eb, answer;
		bool visited[300][300] = { 0 };

		cin >> N;		
		cin >> sa >> sb >> ea >> eb;
		que.push({sa, sb, 0});
		while (!que.empty()) {
			Knite front = que.front();
			que.pop();
			if (front.a == ea && front.b == eb) {
				answer = front.count;
				break;
			}

			for (int i = 0; i < 8; i++) {
				int tmpa = front.a + da[i];
				int tmpb = front.b + db[i];

				if (tmpa < 0 || tmpa >= N || tmpb < 0 || tmpb >= N)
					continue;
				if (!visited[tmpa][tmpb]) {
					visited[tmpa][tmpb] = true;
					que.push({ tmpa, tmpb, front.count + 1 });
				}
			}
		}
		cout << answer << endl;

	}
	return 0;
}