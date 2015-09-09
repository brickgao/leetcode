#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    bool searchMatrix(vector < vector <int> >& matrix, int target) {
        if (SZ(matrix) == 0)
            return false;
        int m = SZ(matrix), n = SZ(matrix[0]);
        int l = 0, r = m - 1;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target)
                r = mid;
            else
                l = mid;
        }
        int col = -1;
        if (matrix[r][0] <= target)      col = r;
        else                            col = l;
        l = 0, r = n - 1;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if (matrix[col][mid] == target)
                return true;
            else if (matrix[col][mid] > target)
                r = mid;
            else
                l = mid;
        }
        if (matrix[col][l] == target || matrix[col][r] == target)   return true;
        else                                                        return false;
    }
};

int main() {
    Solution solution = Solution();
    vector <vector <int> > input;
    input.push_back(vector <int> {1});
    input.push_back(vector <int> {3});
    cout << solution.searchMatrix(input, 3) << endl;
    return 0;
}
