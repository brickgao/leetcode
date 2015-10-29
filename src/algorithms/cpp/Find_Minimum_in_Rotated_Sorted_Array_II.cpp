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
    int findMin(vector<int>& nums) {
        int l = 0, r = SZ(nums) - 1;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if (nums[mid] > nums[r])        l = mid;
            else if (nums[mid] < nums[r])   r = mid;
            else {
                if (mid >= 1) {
                    if (nums[l] == nums[mid] && nums[mid - 1] == nums[mid])   l = mid;
                    else                                                      r = mid;
                }
                else {
                    break;
                }
            }
        }
        if (nums[l] < nums[r])      return nums[l];
        else                        return nums[r];
    }
};

int main() {
    vector <int> v1 = {0, 1, 2, 2, 2, 3, 4};
    vector <int> v2 = {4, 0, 1, 2, 2, 2, 3};
    vector <int> v3 = {3, 0, 1, 2, 3, 3, 3};
    vector <int> v4 = {0, 0, 0, 0, 0, 1, 1};
    vector <int> v5 = {3, 3, 1, 3};
    vector <int> v6 = {10, 1, 10, 10, 10};
    vector <int> v7 = {1, 10, 10, 10, 10};
    Solution solution = Solution();
    cout << solution.findMin(v1) << endl;
    cout << solution.findMin(v2) << endl;
    cout << solution.findMin(v3) << endl;
    cout << solution.findMin(v4) << endl;
    cout << solution.findMin(v5) << endl;
    cout << solution.findMin(v6) << endl;
    cout << solution.findMin(v7) << endl;
    return 0;
}
