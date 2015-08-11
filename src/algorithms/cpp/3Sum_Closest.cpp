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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = -0xfffff;
        for (int i = 0; i < SZ(nums) - 2; ++ i) {
            int l = i + 1, r = SZ(nums) - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > target)   r -= 1;
                else if (sum < target)  l += 1;
                else return target;
                if (abs(result - target) > abs(sum - target))
                    result = sum;
            }
        }
        return result;
    }
};


int main() {
    vector <int> v;
    Solution solution = Solution();
    v.push_back(0), v.push_back(0), v.push_back(0);
    cout << solution.threeSumClosest(v, 1) << endl;
    return 0;
}
