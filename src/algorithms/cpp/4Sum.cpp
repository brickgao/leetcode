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
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector <int> > results;
        map <int, int> mp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < SZ(nums) - 3; ++ i) {
            if (nums[i] > target / 4)   continue;
            while (i >= 1 && nums[i] == nums[i - 1])    ++ i;
            for (int j = i + 1; j < SZ(nums) - 2; ++ j) {
                while (j != i + 1 && nums[j] == nums[j - 1])    ++ j;
                if (nums[j] > (target - nums[i]) / 3)   continue;
                int l = j + 1, r = SZ(nums) - 1;
                while (l < r) {
                    while (l < r && l != j + 1 && nums[l] == nums[l - 1])  ++ l;
                    if (l == r)     break;
                    int tmp = nums[i] + nums[j] + nums[l] + nums[r];
                    if (tmp < target)       l += 1;
                    else if (tmp > target)  r -= 1;
                    else {
                        vector <int> v;
                        v.push_back(nums[i]), v.push_back(nums[j]);
                        v.push_back(nums[l]), v.push_back(nums[r]);
                        results.push_back(v);
                        l += 1;
                    }
                }
            }
        }
        return results;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> v;
    v.push_back(0), v.push_back(1), v.push_back(5), v.push_back(0);
    v.push_back(1), v.push_back(5), v.push_back(5), v.push_back(-4);
    vector <vector <int> > results = solution.fourSum(v, 11);
    for (int i = 0; i < SZ(results); ++ i) {
        cout << results[i][0] << " " << results[i][1] << " " << results[i][2] << " " << results[i][3] << endl;
    }
    return 0;
}
