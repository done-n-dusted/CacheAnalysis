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

vector<int> gather(vector <vector <int> > indexes, vector <int> gather_array){
	for(int i = 0; i < indexes.size(); i++){
		int row_loc = indexes[i][0];
		int col_loc = indexes[i][1];

		gather_array[i] = memory_array[row_loc][col_loc];
	}
	return gather_array;
}

void print_vector(vector <int> v){
	for(int i: v){
		cout << i << " ";
	}
	cout << '\n';
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

	vector <int> output_array {45, 223, 112, 334, 91};
	cout << "output array:";
	print_vector(output_array);
	// cout << filename;
	// vector <vector <int> > A = read_matrix(filename);
	cout << "Matrix:\n";
	printMatrix(memory_array);
    parsec_roi_begin();
	output_array = gather(indexes, output_array);
	parsec_roi_end();
	cout << "updated:";
	print_vector(output_array);
	return 0;
}
