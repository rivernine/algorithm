#include <iostream>
#include <deque>
#include <string>

using namespace std;

int N;
deque<int> dque;

void push(int n) {
	dque.push_back(n);
}
void pop() {
	if (!dque.empty()) {
		cout << dque.front() << "\n";
		dque.pop_front();
	}
	else {
		cout << -1 << "\n";
	}
}
void size() {
	cout << dque.size() << "\n";
}
void empty() {
	if (dque.empty())
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
}
void front() {
	if (!dque.empty())
		cout << dque.front() << "\n";
	else
		cout << -1 << "\n";
}
void back() {
	if (!dque.empty())
		cout << dque.back() << "\n";
	else
		cout << -1 << "\n";
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		if (input == "push") {
			int tmp;
			cin >> tmp;
			push(tmp);
		}
		else if (input == "pop") {
			pop();
		}
		else if (input == "size") {
			size();
		}
		else if (input == "empty") {
			empty();
		}
		else if (input == "front") {
			front();
		}
		else if (input == "back") {
			back();
		}
	}
	return 0;
}