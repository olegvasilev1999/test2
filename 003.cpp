# test2
#include <iostream>
#include <sstream>

using namespace std;

auto input(std::istream & stream,
	float ** & result_elements,
	unsigned int & result_rows,
	unsigned int & result_columns)->std::istream &
{
	unsigned int rows = 0;
	unsigned int columns = 0;
	char symbol;
	float ** elements = nullptr;

	bool success = true;

	string line;
	if (getline(stream, line)) {
		istringstream sstream(line);
		if (sstream >> rows && sstream >> symbol && symbol == ',' && sstream >> columns && sstream.eof()) {
			elements = new float *[rows];
			for (unsigned int i = 0; i < rows && success; i++) {
				elements[i] = new float[columns];
				string line;
				if (getline(stream, line)) {
					istringstream sstream(line);
					for (unsigned j = 0; j < columns; j++) {
						sstream >> elements[i][j];
						if (!sstream) {
							success = false;
							break;
						}
					}

					success &= sstream.eof();
				}
				else {
					success = false;
				}
			}
		}
		else {
			success = false;
		}
	}

	if (success) {
		result_elements = elements;
		result_rows = rows;
		result_columns = columns;
	}
	else {
		stream.setstate(ios_base::failbit);
	}

	return stream;
}


void destroy(float ** elements,
	unsigned int rows)
{
	for (unsigned int i = 0; i < rows; ++i) {
		delete[] elements[i];
	}
	delete[] elements;
}

auto output(std::ostream & stream,
	float ** elements,
	unsigned int rows,
	unsigned int columns)->std::ostream & {
	cout << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			stream << elements[i][j] << ' ';
		}
		stream << endl;
	}
	return stream;
}

float * mtrxtomas(float ** array,unsigned int rows,unsigned int columns) {
	float * result = new float [columns];

	for (int i = 0; i < columns; i++) {
		result[i] = array[0][i];
	}
	for (int i = 1, j = columns; i < rows; i++,j++ ) {
		result[j] = array[i][columns-1];
	}
	for (int i = columns - 2, j = columns + rows-1; i >=0; i--, j++) {
		result[j] = array[rows-1][i];
	}
	for (int i = rows - 2, j = 2*columns + rows - 2; i >= 0; i--, j++) {
		result[j] = array[i][0];
	}

	return result;
}

float ** mastomtrx(float * array, float ** result, unsigned int rows, unsigned int columns) {
	
	for (int i = 0; i < columns; i++) {
		result[0][i] = array[i] ;
	}

	for (int i = 1, j = columns; i < rows; i++, j++) {
		 result[i][columns - 1] = array[j];
	}
	for (int i = columns - 2, j = columns + rows - 1; i >= 0; i--, j++) {
		result[rows - 1][i] = array[j] ;
	}
	for (int i = rows - 2, j = 2 * columns + rows - 2; i > 0; i--, j++) {
		 result[i][0] = array[j];
	}

	return result;
}

float * swapp(float * array, int k) {
	int j = k - 1;
	for (int i = 0; i < k / 2; i++) {
		swap(array[i], array[j]);
		j--;
	}
	return array;
}

int main()
{
	float ** matrix;
	unsigned int rows, columns;
	bool success = true;
	int k;
	
	if (input(cin, matrix, rows, columns) ) {
		string str;
		getline(cin, str);
		istringstream stream(str);
		if (stream >> k) {
			int n = 2 * columns + 2 * rows - 4;
			float * array = new float[n];
			array = mtrxtomas(matrix, rows, columns);

			float * array1 = new float[n - k];
			for (int i = 0; i < n - k; i++) {
				array1[i] = array[i];
			}
			float * array2 = new float[k];

			for (int i = n - k, j = 0; i < n; i++, j++) {
				array2[j] = array[i];

			}
			array1 = swapp(array1, n - k);
			array2 = swapp(array2, k);

			for (int i = 0; i < n - k; i++) {
				array[i] = array1[i];
			}
			int	j = 0;
			for (int i = n - k; i < n; i++) {
				array[i] = array2[j];
				j++;
			}
			array = swapp(array, n);

			matrix = mastomtrx(array, matrix, rows, columns);

			delete[] array;
			delete[] array1;
			delete[] array2;

			output(cout, matrix, rows, columns);

			destroy(matrix, rows);
		}
		else cout << "An error has occured while reading input data";
	
	}
	else cout << "An error has occured while reading input data";


	cin.get();
	cin.get();
	return 0;
}
