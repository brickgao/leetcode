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
    map <int, vector <int> > mp;
    vector <int> in;
    vector <int> vis;
    bool result = true;

private:
    void dfs(int u) {
        for (auto &v: mp[u]) {
            if (vis[v] <= in[v]) {
                ++ vis[v];
                if (vis[v] == in[v]) {
                    ++ vis[v];
                    dfs(v);
                }
            }
            else {
                result = false;
            }
        }
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        for (int i = 0; i < numCourses; ++ i) {
            vis.push_back(0);
            in.push_back(0);
        }
        for (auto &p: prerequisites) {
            mp[p.second].push_back(p.first);
            ++ in[p.first];
        }
        for (int i = 0; i < numCourses; ++ i) {
            if (in[i] == 0) {
                ++ vis[i];
                dfs(i);
            }
        }
        for (int i = 0; i < numCourses; ++ i)
            if (!vis[i])    return false;
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <pair <int, int>> input;
    input.push_back(make_pair(0, 1));
    cout << solution.canFinish(2, input) << endl;
    return 0;
}
