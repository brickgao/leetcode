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
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = SZ(nums) - 1;
        int found = -1;
        vector <int> result;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                found = mid;
                break;
            }
            else if (nums[mid] > target){
                r = mid;
            }
            else {
                l = mid;
            }
        }
        if (target == nums[l])      found = l;
        else if (target == nums[r]) found = r;
        if (found == -1) {
            result.push_back(-1), result.push_back(-1);
            return result;
        }
        else {
            l = 0, r = found;
            while (l < r - 1) {
                int mid = (l + r) >> 1;
                if (nums[mid] < target) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            if (target == nums[l])      result.push_back(l);
            else if (target == nums[r]) result.push_back(r);
            l = found, r = SZ(nums) - 1;
            while (l < r - 1) {
                int mid = (l + r) >> 1;
                if (nums[mid] > target) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            if (target == nums[r])      result.push_back(r);
            else if (target == nums[l]) result.push_back(l);
        }
        return result;
    }
};


int main() {
    return 0;
}
