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
    map <int, int> mp, re_mp;
    int cnt[10000], total;
    vector <vector <int> > result;
    vector <int> nums, tmp;

private:
    void dfs() {
        bool tag = false;
        for (int i = 1; i < total; ++ i) {
            if (cnt[i] != 0) {
                -- cnt[i], tmp.push_back(mp[i]);
                tag = true;
                dfs();
                ++ cnt[i], tmp.pop_back();
            }
        }
        if (!tag) {
            vector <int> ele = tmp;
            result.push_back(ele);
        }
    }

public:
    vector<vector <int> > permuteUnique(vector <int> & nums) {
        this->nums = nums, total = 1;
        for (int i = 0; i < SZ(nums); ++ i) {
            if (re_mp[nums[i]] == 0) {
                re_mp[nums[i]] = total;
                mp[total] = nums[i];
                cnt[total] = 1;
                ++ total;
            }
            else {
                ++ cnt[re_mp[nums[i]]];
            }
        }
        dfs();
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> input;
    input.push_back(1), input.push_back(1), input.push_back(2);
    vector <vector <int> > result = solution.permuteUnique(input);
    for (int i = 0; i < SZ(result); ++ i) {
        for (int j = 0; j < SZ(result[i]); ++ j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
