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

bool cmp(pair <int, int> &a, pair <int, int> &b) {
    return a.first > b.first;
}

class Solution {
public:
    vector<int> topKFrequent(vector <int>& nums, int k) {
        map <int, int> mp;
        vector <int> result;
        vector <pair<int, int>> v;
        for (int num: nums)     ++ mp[num];
        for (auto it = mp.cbegin(); it != mp.cend(); ++ it)
            v.push_back(make_pair(it->second, it->first));
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < k; ++ i)    result.push_back(v[i].second);
        return result;
    }
            
};
