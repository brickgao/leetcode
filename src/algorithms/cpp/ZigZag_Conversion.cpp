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
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string s_l[1000];
        int row = 0, mv = 1;
        for (int i = 0; i < SZ(s); ++ i) {
            s_l[row] += s[i];
            if (row == numRows - 1) {
                mv = -1;
            }
            if (row == 0) {
                mv = 1;
            }
            row += mv;
        }
        string result = "";
        for (int i = 0; i < numRows; ++ i) {
            result += s_l[i];
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.convert("PAYPALISHIRING", 3) << endl;
    cout << "PAHNAPLSIIGYIR" << endl;
    return 0;
}
