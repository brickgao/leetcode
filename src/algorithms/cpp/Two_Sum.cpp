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
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, vector<int> > mp;
        vector <int> result;
        for (int i = 0; i < SZ(nums); ++ i) {
            if(!mp[target - nums[i]].empty()) {
                result.push_back(mp[target - nums[i]][0] + 1), result.push_back(i + 1);
                return result;
            }
            mp[nums[i]].push_back(i);
        }
        result.push_back(0), result.push_back(0);
        return result;
    }
};

int main() {
    Solution solution = Solution();
    int input[4] = {2, 7, 11, 16};
    vector <int> input_v;
    for (int i = 0; i < 4; ++ i) {
        input_v.push_back(input[i]);
    }
    vector <int> result = solution.twoSum(input_v, 9);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
