#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

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


vector <vector<int> > matrix_transpose(vector< vector<int> > A){
	int rows = A.size();
	int columns = A[0].size();

	vector <int> temp(rows, 0);
	vector <vector <int> > result(columns, temp);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			result[i][j] = A[j][i];
		}
	}

	return result;
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
		filename = "mat_transpose.in";
	} else {
		filename = argv[2];
	}

	// cout << filename;
	vector <vector <int> > A = read_matrix(filename);
	printMatrix(A);
    parsec_roi_begin();
	vector< vector<int> > A_transpose = matrix_transpose(A);
    parsec_roi_end();
	printMatrix(A_transpose);
	return 0;
}
