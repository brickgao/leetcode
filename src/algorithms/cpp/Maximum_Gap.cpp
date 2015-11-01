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
    int maximumGap(vector<int>& nums) {
        if (SZ(nums) < 2)       return 0;
        int maxn = -maxint, minn = maxint;
        for (auto &num: nums) {
            get_max(maxn, num);
            get_min(minn, num);
        }
        int capacity = ceil(static_cast <double> (maxn - minn) / static_cast <double> (SZ(nums)));
        if (capacity == 0)      return 0;
        vector <pair <int, int> > rec (SZ(nums) + 1, make_pair(-maxint, maxint));
        for (int i = 0; i < SZ(nums); ++ i) {
            int pos = (nums[i] - minn) / capacity;
            rec[pos] = make_pair(max(rec[pos].first, nums[i]), min(rec[pos].second, nums[i]));
        }
        int ret = 0, pre = 0;
        for (int i = 1; i < SZ(rec); ++ i) {
            if (rec[i].first == -maxint)    continue;
            get_max(ret, rec[i].second - rec[pre].first);
            pre = i;
        }
        return ret;
    }
};

int main() {
    vector <int> v = {100, 3, 2, 1};
    Solution solution = Solution();
    cout << solution.maximumGap(v) << endl;
    return 0;
}
