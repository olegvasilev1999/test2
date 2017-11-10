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
			}
				success &= sstream.eof();
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

float ** getmtrx(float ** array, unsigned int rows, unsigned int columns) {

	int r = 0, h = 1, m1 = 0, m3 = columns - 1, m4 = 0, m2 = rows - 1;

	while (m1<(rows / 2) + 1) {
		switch (r) {
		case 0:
			for (int i = m4; i<m3 + 1; i++) { array[m1][i] = h; h++; }
			r++;
			m1++;
			break;
		case 1:
			for (int i = m1; i<m2 + 1; i++) { array[i][m3] = h; h++; }
			r++;
			m3--;
			break;
		case 2:
			for (int i = m3; i>m4 - 1; i--) { array[m2][i] = h; h++; }
			r++;
			m2--;
			break;
		case 3:
			for (int i = m2; i>m1 - 1; i--) { array[i][m4] = h; h++; }
			r = 0;
			m4++;
			break;
		}

	}
	return array;
}




int main()
{
	float ** matrix;
	unsigned int rows, columns;
	

	if (input(cin, matrix, rows, columns)) {
		matrix = getmtrx(matrix, rows, columns);
		output(cout, matrix, rows, columns);
	}
	else cout << "An error has occured while reading input data";


	cin.get();
	cin.get();
	return 0;
}
