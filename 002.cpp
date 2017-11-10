# test2
#include <iostream>
#include <sstream>


using namespace std;

bool read_numbers(int & n, int * array)
{
	string string;
	getline(cin, string);
	istringstream stream(string);

	bool success = true;

	for (int i = 0; i < n; ++i) {
		if (!(stream >> array[i])) {
			success = false;
			break;
		}
	}
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
		int k = 0;
		if (read_numbers(n, array) && n > 0) {
			if (!(cin >> k) || (k <= 0))
			{
				cout << "An error has occured while reading input data.\n";
				return 0;
			}
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
			
		}
		else {
			cout << "An error has occured while reading input data.";
		}
	}

	cin.get();
	cin.get();
	return 0;
}
