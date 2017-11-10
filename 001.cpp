# test2

#include <iostream>
#include <sstream>

using namespace std;

bool read_numbers(int & n, int * array)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	int element = -1;
	bool success = true;

	for (int i = 0; i < n; ++i) {
		if (!(stream >> array[i])) {
			success = false;
			break;
		}
	}
	if (stream >> element) success = false;
	
	return success;
}

int main() {
	int n;
	string str;

	getline(cin, str);
	istringstream stream(str);

	if (stream >> n) {
		int k = abs(n);
		int * array = new int[k];
		if (read_numbers(n, array) && n > 0) {
	
			int j = n - 1;
			for (int i = 0; i < n / 2 ; i++) { 
				swap(array[i], array[j]);
				j--;
			}
			for (int i = 0; i < n; i++) {
				cout << array[i] << " ";
			}
			
			delete[]  array;
		}
		else {
			cout << "An error has occured while reading input data.";
		}
	}

	cin.get();
	cin.get();
	return 0;
}
