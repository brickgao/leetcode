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
    vector<int> majorityElement(vector<int>& nums) {
        if (SZ(nums) == 0)      return vector <int> {};
        int num1 = maxint, num2 = maxint;
        int cnt1 = 0, cnt2 = 0;
        for (int num: nums) {
            if (cnt1 == 0 || num1 == num) {
                num1 = num;
                cnt1 += 1;
            }
            else if (cnt2 == 0 || num2 == num) {
                num2 = num;
                cnt2 += 1;
            }
            else {
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int num: nums) {
            if (num == num1)             cnt1 += 1;
            else if (num == num2)        cnt2 += 1;
        }
        vector <int> ret;
        if (cnt1 > SZ(nums) / 3.0)        ret.push_back(num1);
        if (cnt2 > SZ(nums) / 3.0)        ret.push_back(num2);
        return ret;
    }
};

int main() {
    return 0;
}
