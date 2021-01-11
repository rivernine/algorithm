#include <iostream>

using namespace std;


long long p = 1000000007;
long long answer = 1;

long long facto(long long n) {
	long long result = 1;
	for (long long i = 1; i <= n; i++) 
		result = (result * i) % p;
	return result;
}

long long comb(long long a, long long r, long long result) {
	if (r == 2)
		return (((a * a) % p) * result) % p;
	else if (r == 1)
		return ((a % p) * result) % p;
	else if (r == 0)
		return result % p;

	if (r % 2 == 0) 
		return comb((a * a) % p, r / 2, result);
	else 
		return comb((a * a) % p, (r - 1) / 2, (result * a) % p);	
}

int main() {
	int N, K;
	cin >> N >> K;
	
	answer = facto(N);
	//cout << answer << endl;

	answer = (answer * comb(facto(N - K), p - 2, 1)) % p;
	//cout << "facto: " << facto(N - K) << endl;
	//cout << "comb: " << comb(facto(N - K), p - 2, 1) << endl;
	//cout << answer << endl;
	answer = (answer * comb(facto(K), p - 2, 1)) % p;
	
	// cout << "facto: " << facto(K) << endl;
	// cout << "comb: " << comb(facto(K), p - 2, 1) << endl;
	cout << answer << endl;


	return 0;
}