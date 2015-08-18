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
    void nextPermutation(vector<int>& nums) {
        int pos = -1;
        for (int i = SZ(nums) - 1; i > 0; -- i) {
            if (nums[i] > nums[i - 1]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            sort(nums.begin(), nums.end());
        }
        else {
            sort(nums.begin() + pos, nums.end());
            for (int i = pos; i < SZ(nums); ++ i) {
                if (nums[i] > nums[pos - 1]) {
                    swap(nums[i], nums[pos - 1]);
                    break;
                }
            }
        }
    }
};


int main() {
    vector <int> v;
    v.push_back(1), v.push_back(2);
    Solution solution = Solution();
    solution.nextPermutation(v);
    return 0;
}
