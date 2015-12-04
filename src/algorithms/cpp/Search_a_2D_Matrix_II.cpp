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

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {       
        int x = 0, y = SZ(matrix[0]) - 1;
        while (0 <= x && x < SZ(matrix) && 0 <= y && y < SZ(matrix[0])) {
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] > target)
                -- y;
            else
                ++ x;
        }
        return false;
    }
};

int main() {
    return 0;
}
