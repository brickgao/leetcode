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
    vector <int> plusOne(vector <int>& digits) {
        int left = 1;
        for (int i = SZ(digits) - 1; i >= 0; -- i) {
            digits[i] += left;
            left = digits[i] / 10;
            digits[i] %= 10;
        }
        if (left)
            digits.insert(digits.begin(), left);
        return digits;
    }
};

int main() {
    vector <int> v;
    v.push_back(9), v.push_back(9);
    Solution solution = Solution();
    vector <int> result = solution.plusOne(v);
    for (int i = 0; i < SZ(result); ++ i) {
        cout << result[i] << endl;
    }
    return 0;
}
