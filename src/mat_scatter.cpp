#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

void parsec_roi_begin() 
{

}

void parsec_roi_end() 
{

}

vector <vector <int> > read_matrix(string filename){
	vector <vector <int> > A;
	string line;
	ifstream infile;
	infile.open(filename.c_str());
	int i = 0;
		while (getline(infile, line) && !line.empty()) {
			istringstream iss(line);
			A.resize(A.size() + 1);
			int a, j = 0;
			while (iss >> a) {
				A[i].push_back(a);
				j++;
			}
			i++;
		}
	infile.close();
	return A;

}

vector <vector <int> > memory_array = read_matrix("../input_files/mat_inp_scatter.in");

void scatter(vector <vector <int> > indexes, vector <int> values){
	for(int i = 0; i < indexes.size(); i++){
		int row_loc = indexes[i][0];
		int col_loc = indexes[i][1];

		memory_array[row_loc][col_loc] = values[i];
	}

}

void printMatrix(vector< vector<int> > matrix) {
	vector< vector<int> >::iterator it;
	vector<int>::iterator inner;
	for (it=matrix.begin(); it != matrix.end(); it++) {
		for (inner = it->begin(); inner != it->end(); inner++) {
			cout << *inner;
			if(inner+1 != it->end()) {
				cout << "\t";
			}
		}
		cout << endl;
	}
}

int main (int argc, char* argv[]) {
	string filename;

	cout << argv[0];
	if (argc < 3) {
		filename = "mat_inp_scatter.in";
	} else {
		filename = argv[2];
	}

	vector <vector <int> > indexes {
		{2, 3},
		{1, 0},
		{6, 2},
		{4, 3},
		{2, 4}
	};

	vector <int> values {77, 66, 55, 88, 99};

	// cout << filename;
	// vector <vector <int> > A = read_matrix(filename);
	printMatrix(memory_array);
    parsec_roi_begin();
	scatter(indexes, values);
	parsec_roi_end();
	printMatrix(memory_array);
	return 0;
}
