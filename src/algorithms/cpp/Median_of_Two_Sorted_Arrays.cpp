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
private:
    static int getKthNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = SZ(nums1), n = SZ(nums2);
        if (m > n) {
            return getKthNumber(nums2, nums1, k);
        }
        if (!m) {
            return nums2[k - 1];
        }
        if (k == 1) {
            return min(nums1[0], nums2[0]);
        }
        int pa = min(k / 2, m);
        int pb = k - pa;
        if (nums1[pa - 1] < nums2[pb - 1]) {
            vector <int> n_nums1 (nums1.begin() + pa, nums1.end());
            return getKthNumber(n_nums1, nums2, k - pa);
        }
        else if (nums1[pa - 1] > nums2[pb - 1]) {
            vector <int> n_nums2 (nums2.begin() + pb, nums2.end());
            return getKthNumber(nums1, n_nums2, k - pb);
        }
        else {
            return nums1[pa - 1];
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = SZ(nums1), n = SZ(nums2);
        if ((m + n) % 2) {
            return double(getKthNumber(nums1, nums2, (m + n) / 2 + 1));
        }
        else {
            return double(getKthNumber(nums1, nums2, (m + n) / 2 + 1) + \
                          getKthNumber(nums1, nums2, (m + n) / 2)) / 2.0;
        }
    }
};

int main() {
    vector <int> v1, v2;
    v1.push_back(1), v1.push_back(4), v1.push_back(5);
    v2.push_back(2), v2.push_back(3), v2.push_back(6);
    Solution solution = Solution();
    cout << solution.findMedianSortedArrays(v1, v2) << endl;
    return 0;
}
