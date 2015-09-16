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
    bool vis[100000] = {};
    vector <int> result, tmp;
    int upper, n;

private:
    void dfs(int u) {
        if (SZ(tmp) == upper)   result = tmp;
        if (SZ(result) != 0)    return;
        for (int i = 0; i < n; ++ i) {
            int v = u ^ (1 << i);
            if (!vis[v]) {
                vis[v] = true;
                tmp.push_back(v);
                dfs(v);
                break;
            }
        }
    }

public:
    vector <int> grayCode(int n) {
        if (n == 0) return vector <int> {0};
        this->n = n;
        memset(vis, false, sizeof(vis));
        upper = 1 << n;
        vis[0] = true;
        tmp.push_back(0);
        dfs(0);
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> result = solution.grayCode(2);
    for (auto num: result)
        cout << num << endl;
    return 0;
}
