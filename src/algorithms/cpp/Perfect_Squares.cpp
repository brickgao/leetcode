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
public:
    int numSquares(int n) {
        vector <bool> vis(n + 1, false);
        queue <pair <int, int>> q;
        q.push(make_pair(n, 0));
        while (!q.empty()) {
            pair <int, int> top = q.front();
            q.pop();
            for (int i = int(sqrt(top.first)); i >= 1; -- i) {
                pair <int, int> tmp = make_pair(top.first - i * i, top.second + 1);
                if (tmp.first == 0)     return tmp.second;
                if (!vis[tmp.first]) {
                    vis[tmp.first] = true;
                    q.push(tmp);
                }
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}
