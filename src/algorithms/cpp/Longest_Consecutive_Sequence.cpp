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
    int longestConsecutive(vector<int> &nums) {
        map <int, int> mp;
        int length = SZ(nums);
        for (auto &num: nums)   mp[num] = -1;
        for (auto &num: nums) {
            if (mp[num] == -1) {
                int cnt = 0;
                for (int i = 1; i <= length; ++ i) {
                    if (mp[num - i] != 0) {
                        cnt = i;
                        if (mp[num - i] != -1)  break;
                    }
                    else {
                        mp[num - i + 1] = 1;
                        cnt = i - 1;
                        break;
                    }
                }
                for (int i = cnt; i > 0; -- i)
                    mp[num - i + 1] = mp[num - i] + 1;
            }
        }
        int result = 0;
        for (auto &num: nums)
            get_max(result, mp[num]);
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> input_v {100, 4, 200, 1, 3, 2};
    cout << solution.longestConsecutive(input_v) << endl;
    return 0;
}
