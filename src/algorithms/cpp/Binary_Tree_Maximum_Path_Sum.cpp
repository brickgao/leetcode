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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int result;

private:
    int dfs(TreeNode *root) {
        if (root == NULL)   return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int ret = root->val;
        if (l > 0)  ret += l;
        if (r > 0)  ret += r;
        get_max(result, ret);
        return max(max(root->val, root->val + l), root->val + r);
    }

public:
    int maxPathSum(TreeNode* root) {
        result = -0xfffffff;
        dfs(root);
        return result;
    }
};

int main() {
    TreeNode *node11 = new TreeNode(1), *node21 = new TreeNode(2), *node22 = new TreeNode(3);
    node11->left = node21, node11->right = node22;
    Solution solution = Solution();
    cout << solution.maxPathSum(node11) << endl;
    return 0;
}
