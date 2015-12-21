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
    map <int, vector <int>> mp;
    vector <bool> vis;
    vector <int> tmp, longest_path;
    int longest_pt, max_len, n;

public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (SZ(edges) == 0)     return vector <int> {0};
        this->longest_pt = 0;
        this->max_len = 0;
        this->n = n;
        for (int i = 0; i < SZ(edges); ++ i) {
            mp[edges[i].first].push_back(edges[i].second);
            mp[edges[i].second].push_back(edges[i].first);
        }
        for (int i = 0; i < n; ++ i)   vis.push_back(false);
        vis[0] = true;
        dfs(0, 1);
        for (int i = 0; i < n; ++ i)   vis[i] = false;
        this->max_len = 0;
        tmp.push_back(longest_pt);
        vis[longest_pt] = true;
        dfs_twice(longest_pt, 1);
        int mid = this->max_len / 2;
        if (this->max_len % 2 == 0)     return vector <int> {this->longest_path[mid - 1], this->longest_path[mid]};
        else                            return vector <int> {this->longest_path[mid]};
    }

private:
    void dfs(int u, int len) {
        if (len > max_len) {
            this->max_len = len;
            this->longest_pt = u;
        }
        for (int v: mp[u]) {
            if (!vis[v]) {
                vis[v] = true;
                this->dfs(v, len + 1);
            }
        }
    }

    void dfs_twice(int u, int len) {
        if (len > max_len) {
            this->max_len = len;
            this->longest_path = this->tmp;
        }
        for (int v: mp[u]) {
            if (!vis[v]) {
                vis[v] = true;
                this->tmp.push_back(v);
                this->dfs_twice(v, len + 1);
                this->tmp.pop_back();
            }
        }
    }
};

int main() {
    return 0;
}
