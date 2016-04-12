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
typedef long long LL;
const LL maxll = 0xfffffffff;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}


class Solution {
private:
    int get_median(vector <int>& nums) {
        int k = (SZ(nums) - 1) / 2 + 1;
        int l = -214748364, r = 214748364;
        while (l < r) {
            int mid = (l < 0 && r > 0) ? (l + r) / 2 : l + (r - l) / 2;
            int larger_cnt = 0, small_cnt = 0, tag = 0;
            for (int &num: nums) {
                if (num < mid) {
                    if (++ small_cnt > k - 1) {
                        tag = 1;
                        break;
                    }
                }
                else if (num > mid) {
                    if (++ larger_cnt > (SZ(nums) - k)) {
                        tag = -1;
                        break;
                    }
                }
            }
            if (tag == 0)
                return mid;
            else if (tag < 0)
                l = mid + 1;
            else
                r = mid;
        }
        return -1;
    }

public:
    void wiggleSort(vector <int>& nums) {
        int median = get_median(nums);
        int mod = SZ(nums) | 1;
        int i = 1 % mod, j = 1 % mod, k = (2 * SZ(nums) - 1) % mod;
        for (int t = 0; t < SZ(nums); ++ t) {
            if (nums[j] > median) {
                swap(nums[i], nums[j]);
                i = (i + 2) % mod;
                j = (j + 2) % mod;
            }
            else if (nums[j] < median) {
                swap(nums[j], nums[k]);
                k = (k - 2 + mod) % mod;
            }
            else {
                j = (j + 2) % mod;
            }
        }
    }
};


int main() {
    Solution solution = Solution();
    vector <int> v = {1, 3, 2, 2, 3, 1};
    solution.wiggleSort(v);
    return 0;
}
