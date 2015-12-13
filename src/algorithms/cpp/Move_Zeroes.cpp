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
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < SZ(nums); ++ i)
            if (nums[i] == 0) {
                while ((j <= i || nums[j] == 0) && j + 1 < SZ(nums))
                    ++ j;
                if (nums[j] == 0)   return;
                swap(nums[i], nums[j]);
            }
    }
};

int main() {
    Solution solution;
    vector <int> nums = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    solution.moveZeroes(nums);
    for (int &num: nums) {
        cout << num << endl;
    }
    return 0;
}
