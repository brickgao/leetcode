#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums[0])               return 0;
        if (target > nums[SZ(nums) - 1])    return SZ(nums);
        int l = 0, r = SZ(nums) - 1;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        if (nums[l] >= target)   return l;
        if (nums[r] >= target)   return r;
    }
};


int main() {
    return 0;
}
