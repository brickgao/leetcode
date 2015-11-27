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
    vector<string> summaryRanges(vector<int>& nums) {
        vector <string> ret;
        if (SZ(nums) == 0)      return ret;
        int beg = 0;
        nums.push_back(nums[SZ(nums) - 1] + 2);
        for (int i = 1; i < SZ(nums); ++ i) {
            if (nums[i] != nums[beg] + i - beg) {
                if (i - 1 == beg)     ret.push_back(to_string(nums[beg]));
                else                  ret.push_back(to_string(nums[beg]) + "->" + to_string(nums[i - 1]));
                beg = i;
            }
        }
        return ret;
    }
};

int main() {
    return 0;
}
