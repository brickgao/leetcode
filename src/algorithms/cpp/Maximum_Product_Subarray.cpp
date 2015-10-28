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
    int maxProduct(vector<int>& nums) {
        int ret = -0xffffff, tmp = 1;
        for (auto &num: nums)    get_max(ret, num);
        for (int i = 0; i < SZ(nums); ++ i) {
            tmp *= nums[i];
            get_max(ret, tmp);
            if (tmp == 0)   tmp = 1;
        }
        tmp = 1;
        for (int i = SZ(nums) - 1; i >= 0; -- i) {
            tmp *= nums[i];
            get_max(ret, tmp);
            if (tmp == 0)   tmp = 1;
        }
        return ret;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> input_v = {-2};
    cout << solution.maxProduct(input_v) << endl;
    return 0;
}
