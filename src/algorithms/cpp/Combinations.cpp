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
    vector <vector <int> > result;
    vector <int> tmp;
    int n, k;

private:
    void dfs(int beg) {
        if (SZ(tmp) == k)   result.push_back(tmp);
        for (int i = beg; i <= n; ++ i) {
            tmp.push_back(i);
            dfs(i + 1);
            tmp.pop_back();
        }
    }

public:
    vector <vector <int> > combine(int n, int k) {
        this->n = n, this->k = k;
        dfs(1);
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <vector <int> > result = solution.combine(4, 2);
    for (auto v: result) {
        for (auto num: v) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
