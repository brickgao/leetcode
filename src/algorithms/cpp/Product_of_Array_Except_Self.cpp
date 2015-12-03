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
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul_all = 1, zero_cnt = 0;
        for (int i = 0; i < SZ(nums); ++ i) {
            if (nums[i] == 0)   zero_cnt += 1;
            else                mul_all *= nums[i];
        }
        vector <int> result;
        for (int i = 0; i < SZ(nums); ++ i) {
            if (nums[i] == 0) {
                if (zero_cnt > 1)   result.push_back(0);
                else                result.push_back(mul_all);
            }
            else {
                if (zero_cnt >= 1)  result.push_back(0);
                else                result.push_back(mul_all / nums[i]);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
