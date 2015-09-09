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
    void sortColors(vector<int>& nums) {
        int b = 0, w = 0, r = SZ(nums) - 1;
        while (w <= r) {
            if (nums[w] == 1)
                w += 1;
            else if (nums[w] == 0) {
                swap(nums[w], nums[b]);
                b += 1, w += 1;
            }
            else {
                while (w < r && nums[r] == 2) {
                    r -= 1;
                }
                swap(nums[w], nums[r]);
                r -= 1;
            }
        }
    }
};

int main() {
    return 0;
}
