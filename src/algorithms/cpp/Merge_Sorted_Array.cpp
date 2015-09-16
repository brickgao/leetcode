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
    void merge(vector <int> &nums1, int m, vector<int> &nums2, int n) {
        int len = SZ(nums1);
        for (int k = 0; k < len - m; ++ k)
            nums1.erase(nums1.begin() + m);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] >= nums2[j]) {
                nums1.insert(nums1.begin() + i, nums2[j]);
                ++ i, ++ j, ++ m;
            }
            else {
                ++ i;
            }
        }
        if (j != n) {
            while (j < n) {
                nums1.insert(nums1.begin() + i, nums2[j]);
                ++ i, ++ j, ++ m;
            }
        }
    }
};

int main() {
    vector <int> v1 = {1, 2, 3, 0, 0, 0};
    vector <int> v2 = {2, 5, 6};
    Solution solution = Solution();
    solution.merge(v1, 3, v2, 3);
    for (auto num: v1)
        cout << num << endl;
    return 0;
}
