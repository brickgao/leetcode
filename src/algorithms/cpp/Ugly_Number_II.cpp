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
    int nthUglyNumber(int n) {
        vector <int> ugly_nums = {1};
        int l2 = 0, l3 = 0, l5 = 0;
        for (int i = 0; i < n - 1; ++ i) {
            ugly_nums.push_back(min(min(ugly_nums[l2] * 2, ugly_nums[l3] * 3), ugly_nums[l5] * 5));
            if (ugly_nums[SZ(ugly_nums) - 1] == ugly_nums[l2] * 2)      ++ l2;
            if (ugly_nums[SZ(ugly_nums) - 1] == ugly_nums[l3] * 3)      ++ l3;
            if (ugly_nums[SZ(ugly_nums) - 1] == ugly_nums[l5] * 5)      ++ l5;
        }
        return ugly_nums[n - 1];
    }
};

int main() {
    return 0;
}
