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
    int minPatches(vector<int>& nums, int n) {
        long long upper_bound = 0;
        int i = 0, result = 0;
        while (upper_bound < n) {
            if (i < SZ(nums) && upper_bound + 1 >= nums[i]) {
                upper_bound += nums[i ++];
            }
            else {
                result += 1;
                upper_bound = 2 * upper_bound + 1;
            }
        }
        return result;
    }
};


int main() {
    return 0;
}
