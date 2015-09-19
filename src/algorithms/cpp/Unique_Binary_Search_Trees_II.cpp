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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector <TreeNode*> result;
    TreeNode *global_root;
    int n;

private:
    vector <TreeNode*> dfs(int beg, int end) {
        vector <TreeNode*> v;
        if (beg > end) {
            v.push_back(NULL);
            return v;
        }
        for (int i = beg; i <= end; ++ i) {
            vector <TreeNode*> l_v = dfs(beg, i - 1);
            vector <TreeNode*> r_v = dfs(i + 1, end);
            for (int l = 0; l < SZ(l_v); ++ l)
                for (int r = 0; r < SZ(r_v); ++ r) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l_v[l];
                    root->right = r_v[r];
                    v.push_back(root);
                }
        }
        return v;
    }

public:
    vector <TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};

int main() {
    Solution solution = Solution();
    cout << SZ(solution.generateTrees(3)) << endl;
    return 0;
}
