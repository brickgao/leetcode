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
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, sum = 0, result = maxint;
        while (r < SZ(nums)) {
            sum += nums[r ++];
            while (sum >= s && l < r) {
                get_min(result, r - l);
                sum -= nums[l ++];
            }
        }
        if (result == maxint)       return 0;
        else                        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> nums = {1, 2, 3, 4, 5};
    cout << solution.minSubArrayLen(11, nums) << endl;
    return 0;
}
