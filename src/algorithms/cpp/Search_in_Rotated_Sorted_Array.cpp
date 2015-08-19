#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = SZ(nums) - 1;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if ((nums[l] <= nums[mid] && nums[mid] <= nums[r]) || (nums[l] >= nums[mid] && nums[mid] >= nums[r])) {
                if (nums[l] < nums[r]) {
                    if (nums[mid] == target)        return mid;
                    else if (nums[mid] > target)    r = mid;
                    else                            l = mid;
                }
                else {
                    if (nums[mid] == target)        return mid;
                    else if (nums[mid] > target)    l = mid;
                    else                            r = mid;
                }
            }
            else { 
                if (nums[mid] > nums[l]) {
                    if (target == nums[mid])             return mid;
                    else if (target > nums[mid])         l = mid;
                    else {
                        if (target == nums[l])           return l;
                        else if (target > nums[l])       r = mid;
                        else                             l = mid;
                    }
                }
                else {
                    if (target == nums[mid])            return mid;
                    else if (target < nums[mid])        r = mid;
                    else {
                        if (target == nums[r])          return r;
                        else if (target > nums[r])      r = mid;
                        else                            l = mid;
                    }
                }
            }
        }
        if (nums[l] == target)      return l;
        else if (nums[r] == target) return r;
        else                        return -1;
    }
};

int main() {
    vector <int> v;
    v.push_back(3), v.push_back(5), v.push_back(1);
    Solution solution = Solution();
    cout << solution.search(v, 3) << endl;
    return 0;
}
