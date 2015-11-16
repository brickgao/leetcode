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
    vector <bool> vis;

public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector <int> result;
        for (int i = 0; i < numCourses; ++ i)   in.push_back(0), vis.push_back(false);
        for (auto p: prerequisites) {
            mp[p.second].push_back(p.first);
            in[p.first] ++;
        }
        while (true) {
            bool flag = false;
            for (int i = 0; i < numCourses; ++ i) {
                if (!vis[i] && in[i] == 0) {
                    for (auto v: mp[i])     -- in[v];
                    flag = true;
                    vis[i] = true;
                    result.push_back(i);
                }
            }
            if (!flag)      break;
        }
        if (SZ(result) == numCourses)   return result;
        else                            return vector <int> {};
    }
};

int main() {
    return 0;
}
