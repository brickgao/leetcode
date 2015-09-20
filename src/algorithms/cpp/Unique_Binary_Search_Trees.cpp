#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
private:
    map <int, int> mp;

private:
    int dfs(const int beg, const int end) {
        int ret = 0;
        if (mp[end - beg] != 0)
            return mp[end - beg];
        if (beg > end) {
            mp[end - beg] = 1;
            return 1;
        }
        for (int i = beg; i <= end; ++ i) {
            int l_num = dfs(beg, i - 1);
            int r_num = dfs(i + 1, end);
            ret += l_num * r_num;
        }
        mp[end - beg] = ret;
        return mp[end - beg];
    }

public:
    int numTrees(int n) {
        return dfs(1, n);
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.numTrees(19) << endl;
    return 0;
}
