#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

class Solution {
private:
    vector <vector <int> > result;
    vector <int> tmp, nums;
    bool vis[10000];

private:
    void dfs() {
        bool tag = false;
        for (int i = 0; i < SZ(nums); ++ i) {
            if (vis[i] == false) {
                vis[i] = true, tag = true;
                tmp.push_back(nums[i]);
                dfs();
                tmp.pop_back();
                vis[i] = false;
            }
        }
        if (!tag) {
            vector <int> ele = tmp;
            result.push_back(ele);
        }
    }

public:
    vector <vector <int> > permute(vector <int> & nums) {
        this->nums = nums;
        for (int i = 0; i < SZ(nums); ++ i) vis[i] = false;
        dfs();
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector <int> input;
    input.push_back(1), input.push_back(2), input.push_back(3);
    vector <vector <int> > result = solution.permute(input);
    for (int i = 0; i < SZ(result); ++ i) {
        for (int j = 0; j < SZ(result[i]); ++ j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
