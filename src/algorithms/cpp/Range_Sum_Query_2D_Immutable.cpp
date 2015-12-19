#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class NumMatrix {
private:
    vector <vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        this->sums.clear();
        if (SZ(matrix) > 0) {
            int m = SZ(matrix), n = SZ(matrix[0]);
            this->sums.push_back(vector <int> (n + 1, 0));
            for (int i = 0; i < m; ++ i) {
                vector <int> sum_line (1, 0);
                for (int j = 0; j < n; ++ j) {
                    sum_line.push_back(sum_line[j] + this->sums[i][j + 1] - this->sums[i][j] + matrix[i][j]);
                }
                this->sums.push_back(sum_line);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return this->sums[row2 + 1][col2 + 1] - this->sums[row2 + 1][col1] - this->sums[row1][col2 + 1] + this->sums[row1][col1];
    }
};

int main() {
    vector <vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5},
    };
                          
    NumMatrix num_matrix(matrix);
    cout << num_matrix.sumRegion(2, 1, 4, 3) << endl;
    cout << num_matrix.sumRegion(1, 1, 2, 2) << endl;
    cout << num_matrix.sumRegion(1, 2, 2, 4) << endl;
    return 0;
}
