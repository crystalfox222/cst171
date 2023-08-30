#include <iostream>
#include <vector>
using namespace std;

int main() {

	int input = 0;
	vector<int> values;

	while (input >= 0) {
		cout << "enter value" << endl;
		cin >> input;
		if (input >= 0) {
				values.push_back(input);
		}
		cout << input << endl;
		cin.ignore(10, '\n');

	}

	int i = 0;
	while (i < values.size() {
		cout << values[i] < < endl;
		i++

	}
	cout << "size" << values.size() << endl;
	cin.get();
	return 0;

}