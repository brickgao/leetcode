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
    vector<vector <int> > threeSum(vector<int>& nums) {
        map <int, vector <int> > mp;
        vector <vector <int> > results;
        set <int> s;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < SZ(nums); ++ i) {
            mp[nums[i]].push_back(i);
            s.insert(nums[i]);
        }
        for (set <int>::iterator iter1 = s.begin(); iter1 != s.end(); ++ iter1)
            for (set <int>::iterator iter2 = s.begin(); iter2 != s.end(); ++ iter2) {
                int tmp = -(*iter1 + *iter2);
                if (!mp[tmp].empty()) {
                    int tag = false;
                    if (*iter1 != *iter2 && tmp < *iter2)   tag = true;
                    if (*iter1 != *iter2 && tmp == *iter2 && SZ(mp[tmp]) >= 2)   tag = true;
                    if (*iter1 == *iter2 && tmp < *iter2 && SZ(mp[*iter1]) >= 2)  tag = true;
                    if (*iter1 == *iter2 && tmp == *iter2 && SZ(mp[tmp]) >= 3)  tag = true;
                    if (tag) {
                        vector <int> result;
                        result.push_back(tmp);
                        result.push_back(*iter2);
                        result.push_back(*iter1);
                        results.push_back(result);
                    }
                }
                if (*iter1 == *iter2)   break;
            }
        return results;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> v;
    //v.push_back(-1), v.push_back(0), v.push_back(1);
    v.push_back(1), v.push_back(1), v.push_back(-2);
    vector <vector <int> > results = solution.threeSum(v);
    for (int i = 0; i < SZ(results); ++ i) {
        cout << results[i][0] << " " << results[i][1] << " " << results[i][2] << endl;
    }
}
