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
    int maxProfit(vector<int>& prices) {
        if (SZ(prices) == 0)    return 0;
        vector <int> maxn_rec, minn_rec;
        minn_rec.push_back(prices[0]), maxn_rec.push_back(0);
        for (int i = 1; i < SZ(prices); ++ i)
            minn_rec.push_back(min(minn_rec[i - 1], prices[i])), maxn_rec.push_back(0);
        maxn_rec[SZ(maxn_rec) - 1] = prices[SZ(prices) - 1];
        for (int i = SZ(prices) - 2; i >= 0; -- i)
            maxn_rec[i] = max(maxn_rec[i + 1], prices[i]);
        int result = 0;
        for (int i = 0; i < SZ(prices); ++ i) {
            get_max(result, maxn_rec[i] - minn_rec[i]);
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> v {1, 4, 2};
    cout << solution.maxProfit(v) << endl;
    return 0;
}
