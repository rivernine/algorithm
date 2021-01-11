#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int r, c, k;
int cura, curb;
int arr[101][101] = { 0 };

void print() {
	cout << endl;
	for (int i = 0; i < cura; i++) {
		for (int j = 0; j < curb; j++) {
			cout << arr[i][j] << " ";
		}cout << endl;
	}
}


void cal(int f1, int f2) {
	for (int i = 0; i < 100; i++) {
		vector<int> tmpvc;
		map<int, int> mp;
		vector<pair<int, int>> result;
		for (int j = 0; j < 100; j++) {
			if (arr[i * f1 + j * f2][i * f2 + j * f1] != 0)
				tmpvc.push_back(arr[i * f1 + j * f2][i * f2 + j * f1]);
		}
		for (int j = 0; j < tmpvc.size(); j++) {
			if (mp.find(tmpvc[j]) == mp.end()) {
				mp[tmpvc[j]] = 1;
			}
			else {
				mp[tmpvc[j]]++;
			}
		}
		
		int mpsize = mp.size() * 2;

		if (f1 == 1 && f2 == 0) {
			curb = mpsize > curb ? mpsize : curb;
			if (curb > 100)		curb = 100;
		} else {
			cura = mpsize > cura ? mpsize : cura;
			if (cura > 100) 	cura = 100;
		}

		for (auto iter = mp.begin(); iter != mp.end(); iter++) {
			result.push_back({ (*iter).second, (*iter).first });
		}
		sort(result.begin(), result.end());
		vector<int> tmpvc2(100, 0);
		for (int j = 0; j < result.size(); j++) {
			tmpvc2[j * 2] = result[j].second;
			tmpvc2[j * 2 + 1] = result[j].first;
		}
		for (int j = 0; j < tmpvc2.size(); j++) {
			arr[i * f1 + j * f2][i * f2 + j * f1] = tmpvc2[j];
		}
	}
}


int main() {
	cin >> r >> c >> k;
	cura = curb = 3;
	for (int i = 0; i < cura; i++) {
		for (int j = 0; j < curb; j++) {
			cin >> arr[i][j];
		}
	}
	// R: 1, 0
	// C: 0, 1
	int time = 0;
	bool flag = false;
	while (true) {
		if (arr[r - 1][c - 1] == k) {
			cout << time << endl;
			break;
		} else if (time > 100) {
			cout << -1 << endl;
			break;
		}

		if (cura >= curb) {
			cal(1, 0);
		} else {
			cal(0, 1);
		}
		/*if (!flag) {
			cout << endl << "R, time: " << time;
			cal(1, 0);
			flag = true;
		} else {
			cout << endl << "C, time: " << time;
			cal(0, 1);
			flag = false;
		}
		print();*/

		time++;
	}

	return 0;
}