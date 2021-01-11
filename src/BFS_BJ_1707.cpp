#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E;

bool BFS(vector<int> *vc, int* visited, int i) {
	queue<int> que;
	que.push(i);	
	visited[i] = 1;

	while (!que.empty()) {
		int fnt = que.front();
		que.pop();
		//cout << "fnt: " << fnt << endl;


		for (int j = 0; j < vc[fnt].size(); j++) {
			int tmp = vc[fnt][j];
			//cout << "tmp: " << tmp << endl;

			if (visited[tmp] == 0) {
				visited[tmp] = 3 - visited[fnt];
				que.push(tmp);
			}
			else if (visited[tmp] == visited[fnt]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	int testcase;
	cin >> testcase;
	for (int k = 0; k < testcase; k++) {				
		vector<int> vc[20001];
		int visited[20001] = { 0 };
		bool isPossible = true;

		cin >> V >> E; 				
		for (int i = 0; i < E; i++) {
			int tmpa, tmpb;
			cin >> tmpa >> tmpb;
			vc[tmpa].push_back(tmpb);
			vc[tmpb].push_back(tmpa);
		}
		
		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				if (!BFS(vc, visited, i)) {
					isPossible = false;
					break;
				}
			}
		}

		/*for (int i = 1; i <= V; i++) {
			cout << visited[i] << " ";
		}cout << endl*/;


		cout << (isPossible ? "YES" : "NO") << endl;

	}

	return 0;
}