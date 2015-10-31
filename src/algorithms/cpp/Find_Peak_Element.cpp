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
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = SZ(nums) - 1;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if (mid > 0 && mid < SZ(nums) - 1) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                    return mid;
                else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
                    l = mid;
                else
                    r = mid;
            }
            else {
                break;
            }
        }
        if (l > 0 && l < SZ(nums) - 1 && nums[l] > nums[l - 1] && nums[l] > nums[l + 1])
            return l;
        if (r > 0 && r < SZ(nums) - 1 && nums[r] > nums[r - 1] && nums[r] > nums[r + 1])
            return r;
        if (nums[l] > nums[r])  return l;
        else                    return r;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> v1 = {2, 1, 2}, v2 = {3, 2, 1}, v3 = {1, 2, 3};
    cout << solution.findPeakElement(v1) << endl;
    cout << solution.findPeakElement(v2) << endl;
    cout << solution.findPeakElement(v3) << endl;
    return 0;
}
