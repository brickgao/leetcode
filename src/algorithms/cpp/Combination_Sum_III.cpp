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
    vector <vector<int>> result;
    vector <int> tmp;
    int n;

private:
    void dfs(int now, int sum, int left) {
        if (left <= 0) {
            if (sum == n)   result.push_back(tmp);
            return;
        }
        if (now == 9)       return;
        for (int i = now + 1; i <= 9; ++ i) {
            tmp.push_back(i);
            dfs(i, i + sum, left - 1);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->n = n;
        for (int i = 1; i <= 9 - k + 1; ++ i) {
            tmp.push_back(i);
            dfs(i, i, k - 1);
            tmp.pop_back();
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector <vector<int>> result = solution.combinationSum3(9, 45);
    for (auto v: result) {
        for (auto num: v)   cout << num << " ";
        cout << endl;
    }
    return 0;
}
