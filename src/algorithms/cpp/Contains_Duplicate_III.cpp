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
typedef long long LL;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, LL t) {
        if (k < 0 || t < 0)     return false;
        LL _t = max(t, 1LL);
        map <LL, LL> mp, r_mp;
        for (int i = 0; i < SZ(nums); ++ i) {
            LL key = nums[i] / _t;
            for (LL j = key - 1; j <= key + 1; ++ j) {
                if (mp.count(j) != 0 && abs(nums[i] - mp[j]) <= t)
                    return true;
            }
            mp[key] = nums[i];
            r_mp[nums[i]] = key;
            if (i >= k) {
                mp.erase(r_mp[nums[i - k]]);
                r_mp.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main() {
    vector <int> input = {1, 2};
    Solution solution;
    cout << solution.containsNearbyAlmostDuplicate(input, 0, 1) << endl;
    return 0;
}
