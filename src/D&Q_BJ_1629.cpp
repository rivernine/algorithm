#include <iostream>

using namespace std;

long long A, B, C;
long long answer = 1;

long long cal(long long A, long long B) {
	//cout << "A: " << A << ", B: " << B << ", answer: " << answer <<  endl;

	if (B == 2)
		return (A * A) % C;
	else if (B == 1)
		return A % C;
	else if (B == 0)
		return 1;
	
	if (B % 2 == 0) {
		return cal((A * A) % C, B / 2);
	} else {
		answer = (answer * A) % C;
		return cal((A * A) % C, (B - 1) / 2);
	}
}


int main() {
	cin >> A >> B >> C;
	long long tmp = cal(A, B);
	//cout << "tmp: " << tmp << endl;
	answer = (answer * tmp) % C;
	cout << answer << endl;
	return 0;
}