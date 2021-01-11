#include <iostream>
#include <string>
#include <map>

using namespace std;

int T, n;

int main() {

	cin >> T;

	for (int testcase = 0; testcase < T; testcase++) {
		cin >> n;
		map<string, int> mp;
		int answer = 1;

		for (int i = 0; i < n; i++) {
			string name, kind;
			cin >> name >> kind;
			if (mp.find(kind) == mp.end()) 
				mp[kind] = 1;
			else 
				mp[kind]++;
		}

		for (auto iter = mp.begin(); iter != mp.end(); iter++) {
			int value = (*iter).second;
			answer *= (value + 1);
		}
		cout << answer - 1 << endl;
	}

	return 0;
}