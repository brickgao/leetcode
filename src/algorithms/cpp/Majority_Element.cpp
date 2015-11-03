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
    int majorityElement(vector<int>& nums) {
        if (SZ(nums) == 0)      return 0;
        int now = nums[0] - 1, cnt = 0;
        for (auto &num: nums) {
            if (num != now) cnt -= 1;
            else            cnt += 1;
            if (cnt < 0) {
                now = num;
                cnt = 1;
            }
        }
        return now;
    }
};

int main() {
    return 0;
}
