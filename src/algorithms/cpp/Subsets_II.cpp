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
    vector <vector <int> > result;
    vector <int> tmp;
    map <int, int> mp;
    
private:
    void dfs(int now, int cnt) {
        if (now == cnt)     result.push_back(tmp);
        for (map <int, int>::iterator it = mp.begin(); it != mp.end(); ++ it) {
            if (SZ(tmp) == 0 || it->first >= tmp[SZ(tmp) - 1]) {
                if (it->second > 0) {
                    -- mp[it->first];
                    tmp.push_back(it->first);
                    dfs(now + 1, cnt);
                    tmp.pop_back();
                    ++ mp[it->first];
                }
            }
        }
    }

public:
    vector <vector <int> > subsetsWithDup(vector<int> &nums) {
        for (int i = 0; i < SZ(nums); ++ i)
            ++ mp[nums[i]];
        for (int i = 0; i <= SZ(nums); ++ i) {
            dfs(0, i);
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> v = {1, 2, 2};
    vector <vector <int> > result = solution.subsetsWithDup(v);
    for (auto v: result) {
        for (auto num: v)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}
