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

int * swapp(int * array, int k) {
	int j = k - 1;
	for (int i = 0; i < k / 2; i++) {
		swap(array[i], array[j]);
		j--;
	}
	return array;
}

int main() {
	int n;
	string str;
	getline(cin, str);
	istringstream stream(str);

	if (stream >> n) {
		int g = abs(n);
		int * array = new int[g];
		int k;
		if (read_numbers(n, array) && n > 0 ) {
			string str;
			getline(cin, str);
			istringstream stream(str);
			if (stream >> k) {

				int * array1 = new int[k];
				for (int i = 0; i < k; i++) {
					array1[i] = array[i];
				}
				int * array2 = new int[n - k];
				int j = k;
				for (int i = 0; i < n - k; i++) {
					array2[i] = array[j];
					j++;
				}
				array1 = swapp(array1, k);
				array2 = swapp(array2, n - k);

				for (int i = 0; i < k; i++) {
					array[i] = array1[i];
				}
				j = 0;
				for (int i = k; i < n; i++) {
					array[i] = array2[j];
					j++;
				}
				array = swapp(array, n);

				for (int i = 0; i < n; i++) {
					cout << array[i] << " ";
				}

				delete[] array;
				delete[] array1;
				delete[] array2;
			}
			else {
				cout << "An error has occured while reading input data.";
			}
		}
		else {
			cout << "An error has occured while reading input data.";
		}
	}
	

	cin.get();
	cin.get();
	return 0;
}

