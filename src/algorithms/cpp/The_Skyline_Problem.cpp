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
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multimap <int, int> mp;
        for (int i = 0; i < SZ(buildings); ++ i) {
            mp.emplace(buildings[i][0], buildings[i][2]);
            mp.emplace(buildings[i][1], - buildings[i][2]);
        }

        multiset <int> heights = {0};
        map <int, int> rec;

        for (auto &p: mp) {
            if (p.second > 0) {
                heights.insert(p.second);
            }
            else {
                heights.erase(heights.find(- p.second));
            }
            rec[p.first] = *heights.rbegin();
        }

        vector <pair<int, int>> ret;
        int pre = -1;
        for (auto &p: rec) {
            if (pre != -1 && p.second == pre)   continue;
            ret.push_back(make_pair(p.first, p.second));
            pre = p.second;
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> input = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    Solution solution;
    vector <pair<int, int>> ret = solution.getSkyline(input);
    for (auto p: ret) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
