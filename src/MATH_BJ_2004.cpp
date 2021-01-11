#include <iostream>

using namespace std;

long long n, m;
struct Status {
	int five, two;
};

Status func(long long n) {
	Status result = { 0, 0 };
	for (long long i = 5; i <= n; i *= 5)
		result.five += n / i;
	for (long long i = 2; i <= n; i *= 2)
		result.two += n / i;


	return result;
}


int main() {
	cin >> n >> m;
	Status answer, tmp;

	answer = func(n);
	tmp = func(n - m);
	answer.five -= tmp.five;
	answer.two -= tmp.two;
	tmp = func(m);
	answer.five -= tmp.five;
	answer.two -= tmp.two;

	cout << (answer.five > answer.two ? answer.two : answer.five) << endl;	

	return 0;
}