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
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 31; i >= 0; -- i) {
            int cnt = 0, tmp = 1 << i;
            for (auto num: nums) {
                if ((tmp & num) != 0)  ++ cnt;
            }
            if (cnt % 3 != 0)   ret = (ret << 1) + 1;
            else                ret <<= 1;
        }
        return ret;
    }
};

int main() {
    vector <int> input {0, 0, 0, 5};
    Solution solution = Solution();
    cout << solution.singleNumber(input) << endl;
    return 0;
}
