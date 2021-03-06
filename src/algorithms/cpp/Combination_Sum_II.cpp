#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
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
    vector<vector <int> > result;
    vector <int> candidates;
    vector <int> cnts;
    vector <int> tmp;

private:
    void dfs(int index, int target) {
        if (target == 0) {
            vector <int> tmp = this->tmp;
            result.push_back(tmp);
        }
        else {
            for (int i = index; i < SZ(candidates); ++ i) {
                if (target < candidates[i])     break;
                for (int j = 1; j <= cnts[i]; ++ j) {
                    for (int k = 0; k < j; ++ k)
                        tmp.push_back(candidates[i]);
                    dfs(i + 1, target - candidates[i] * j);
                    for (int k = 0; k < j; ++ k)
                        tmp.pop_back();
                }
            }
        }
    }

public:
    vector<vector <int> > combinationSum2(vector <int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int pre = candidates[0] - 1, cnt = 0, i = 0;
        while (i < SZ(candidates)) {
            if (candidates[i] == pre) {
                ++ cnt;
            }
            else {
                if (pre != candidates[0] - 1) {
                    this->candidates.push_back(pre);
                    this->cnts.push_back(cnt);
                }
                pre = candidates[i];
                cnt = 1;
            }
            ++ i;
        }
        if (pre != candidates[0] - 1) {
            this->candidates.push_back(pre);
            this->cnts.push_back(cnt);
        }
        dfs(0, target);
        return this->result;
    }
};

int main() {
    vector <int> v;
    v.push_back(2), v.push_back(3);
    v.push_back(6), v.push_back(7);
    Solution solution = Solution();
    vector <vector <int> > result = solution.combinationSum2(v, 7);
    for (int i = 0; i < SZ(result); ++ i) {
        for (int j = 0; j < SZ(result[i]); ++ j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
