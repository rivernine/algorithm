#include <iostream>
#include <string>
#include <set>

using namespace std;

//string str;
char str[101];
char arr[32] = { 'q', 'w', 'e', 'r', 't' ,'y', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b' };

void init() {
	for (int i = 0; i < 16; i++) {
		arr[16 + i] = arr[i] - 32;
	}
}

bool isExist(char symb) {
	for (int i = 0; i < 32; i++) 
		if (arr[i] == symb)
			return true;
	return false;
}

int main() {	
	//int test = ' ';  // 97
	init();
	int left, right, mid;
	left = right = mid = 0;
	cin.getline(str, 101);

	int idx = 0;
	while (true) {
		char tmp = str[idx++];
		if (tmp == '\0') break;

		if (tmp == ' ') {
			mid++;
		}
		else if (isExist(tmp)) {
			left++;
			if (tmp < 97) {
				mid++;
			}
		}
		else {
			right++;
			if (tmp < 97) {
				mid++;
			}
		}
	}

	for (int i = 0; i < mid; i++) {
		if (left <= right)
			left++;
		else
			right++;
	}

	cout << left << " " << right << endl;


	return 0;
}