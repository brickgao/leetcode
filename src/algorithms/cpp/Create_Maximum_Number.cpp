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
private:
    vector <int> getSubMax(vector<int> &nums, int k) {
        vector <int> result;
        int pre = 0;
        for (int i = 0; i < k; ++ i) {
            int maxn = -1, nxt_pre = -1;
            for (int j = pre; j <= SZ(nums) - (k - SZ(result)); ++ j) {
                if (nums[j] > maxn) {
                    maxn = nums[j];
                    nxt_pre = j;
                }
            }
            if (maxn == -1) {
                for (int j = pre; j < SZ(nums); ++ j)   result.push_back(nums[j]);
                break;
            }
            else {
                result.push_back(maxn);
                pre = nxt_pre + 1;
            }
        }
        return result;
    }

public:
    vector <int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector <int> result;
        int m = SZ(nums1), n = SZ(nums2);
        for (int i = max(0, k - n); i <= min(k, m); ++ i) {
            cout << i << " " << k - i << endl;
            vector <int> v1 = getSubMax(nums1, i), v2 = getSubMax(nums2, k - i), tmp;
            while (SZ(v1) > 0 || SZ(v2) > 0) {
                if (v1 > v2) {
                    tmp.push_back(v1[0]);
                    v1.erase(v1.begin());
                }
                else {
                    tmp.push_back(v2[0]);
                    v2.erase(v2.begin());
                }
            }
            get_max(result, tmp);
        }
        return result;
    }
};

int main() {
    return 0;
}
