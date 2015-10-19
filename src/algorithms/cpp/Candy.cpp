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
    int rec[100000];

    void dfs(int u, int now) {
        for (auto v: mp[u]) {
            if (rec[v] < now + 1) {
                rec[v] = now + 1;
                dfs(v, now + 1);
            }
        }
    }

public:
    int candy(vector <int>& ratings) {
        int result = 0;
        for (int i = 0; i < SZ(ratings); ++ i)
            rec[i] = 0;
        vector <int> mp_in (SZ(ratings), 0);
        for (int i = 0; i < SZ(ratings); ++ i) {
            if (i < SZ(ratings) - 1 && ratings[i] > ratings[i + 1])
                mp[i + 1].push_back(i), ++ mp_in[i];
            if (i > 0 && ratings[i] > ratings[i - 1])
                mp[i - 1].push_back(i), ++ mp_in[i];
        }
        for (int i = 0; i < SZ(ratings); ++ i) {
            if (mp_in[i] == 0) {
                rec[i] = 1;
                dfs(i, 1);
            }
        }
        for (int i = 0; i < SZ(ratings); ++ i)
            result += rec[i];
        return result;
    }
};

int main() {
    return 0;
}
