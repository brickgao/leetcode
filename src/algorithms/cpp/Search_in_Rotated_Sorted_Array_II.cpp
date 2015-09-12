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
    bool search(vector <int> &nums, int target) {
        int l = 0, r = SZ(nums) - 1;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if ((nums[l] < nums[mid] && nums[mid] < nums[r]) || (nums[l] > nums[mid] && nums[mid] > nums[r])) {
                if (nums[l] <= nums[r]) {
                    if (nums[mid] == target)     return true;
                    else if (nums[mid] > target) r = mid;
                    else                         l = mid;
                }
                else {
                    if (nums[mid] == target)     return true;
                    else if (nums[mid] > target) l = mid;
                    else                         r = mid;
                }
            }
            else {
                while (l < r - 1 && nums[l] == nums[r] && nums[l] == nums[mid]) {
                    ++ l;
                    mid = (l + r) >> 1;
                }
                if (nums[mid] >= nums[l]) {
                    if (target == nums[mid])     return true;
                    else if (target > nums[mid]) l = mid;
                    else {
                        if (target == nums[l])      return true;
                        else if (target > nums[l])  r = mid;
                        else                        l = mid;
                    }
                }
                else {
                    if (target == nums[mid])     return true;
                    else if (target < nums[mid]) r = mid;
                    else {
                        if (target == nums[r])      return true;
                        else if (target > nums[r])  r = mid;
                        else                        l = mid;
                    }
                }
            }
        }
        if (target == nums[l] || target == nums[r])  return true;
        else                                         return false;
    }
};

int main() {
    vector <int> v1 = {1, 1, 3, 1};
    vector <int> v2 = {1, 3, 1, 1, 1};
    vector <int> v3 = {0, 0, 1, 1, 2, 0};
    vector <int> v4 = {1, 2, 2, 2, 0};
    Solution solution = Solution();
    cout << solution.search(v1, 3) << endl;
    cout << solution.search(v2, 3) << endl;
    cout << solution.search(v3, 0) << endl;
    cout << solution.search(v4, 0) << endl;
    return 0;
}
