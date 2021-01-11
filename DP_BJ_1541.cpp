#include <iostream>
#include <string>

using namespace std;

string str;

int cal() {
	int result = 0;
	bool plus = true;
	string tmp = "";
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0' ) {
			if (plus) 
				result += stoi(tmp);
			else 
				result -= stoi(tmp);
			
			if (str[i] == '+')
				plus = true;
			else
				plus = false;
			tmp = "";
		}
		else {
			tmp += str[i];

		}
	}

	return result;
}

int main() {
	cin >> str;
	bool flag = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '-' && !flag) {
			flag = true;
		} 
		else if (str[i] == '+' && flag) {
			str[i] = '-';
		}		
	}
	cout << cal() << endl;


	return 0;
}