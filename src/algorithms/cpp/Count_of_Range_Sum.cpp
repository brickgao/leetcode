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
    int countRangeSum(vector <int>& nums, int lower, int upper) {
        multiset <long long> rec = {0};
        long long now_sum = 0;
        int result = 0;
        for (int i = 0; i < SZ(nums); ++ i) {
            now_sum += nums[i];
            auto lower_it = rec.lower_bound(now_sum - upper);
            auto upper_it = rec.upper_bound(now_sum - lower);
            result += distance(lower_it, upper_it);
            rec.insert(now_sum);
        }
        return result;
    }
};


int main() {
    Solution solution = Solution();
    vector <int> nums = {-2, 5, -1};
    cout << solution.countRangeSum(nums, -2, 2) << endl;
    return 0;
}
