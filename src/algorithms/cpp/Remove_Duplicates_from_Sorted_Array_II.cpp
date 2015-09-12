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
    int removeDuplicates(vector <int>& nums) {
        if (SZ(nums) == 0)  return 0;
        int pos = 0, pre = -1, cnt = 0;
        bool tag = false;
        while (pos < SZ(nums)) {
            if (!tag) {
                pre = nums[pos];
                cnt = 1;
                tag = true;
                ++ pos;
            }
            else {
                if (nums[pos] == pre) {
                    if (cnt == 2) {
                        nums.erase(nums.begin() + pos);
                    }
                    else {
                        ++ cnt;
                        ++ pos;
                    }
                }
                else {
                    pre = nums[pos];
                    cnt = 1;
                    ++ pos;
                }
            }
        }
        return SZ(nums);
    }
};

int main() {
    vector <int> input_v = {1, 1, 1, 2, 2, 3};
    Solution solution = Solution();
    cout << solution.removeDuplicates(input_v) << endl;
    for (auto num: input_v)
        cout << num << " ";
    cout << endl;
    return 0;
}
