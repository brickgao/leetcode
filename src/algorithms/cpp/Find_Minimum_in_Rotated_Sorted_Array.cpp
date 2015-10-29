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
        int mid = -1;
        while (l < r - 1) {
            mid = (l + r) >> 1;
            if (nums[mid] > nums[r])    l = mid;
            else                        r = mid;
        }
        if (nums[l] < nums[r])  return nums[l];
        else                    return nums[r];
    }
};

int main() {
    vector <int> v1 = {4, 5, 6, 0, 1, 2};
    vector <int> v2 = {6, 0, 1, 2, 4, 5};
    vector <int> v3 = {0, 1, 2, 3, 4, 5};
    Solution solution = Solution();
    cout << solution.findMin(v1) << endl;
    cout << solution.findMin(v2) << endl;
    cout << solution.findMin(v3) << endl;
    return 0;
}
