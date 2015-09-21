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
typedef long long LL;
const LL maxll = 0xfffffffff;
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
    bool dfs(TreeNode* root, LL l, LL r) {
        bool tag = true;
        if (root->left) {
            LL n_r = root->val;
            get_min(n_r, r);
            if (root->left->val < n_r && root->left->val > l)
                tag = tag && dfs(root->left, l, n_r);
            else
                return false;
        }
        if (root->right) {
            LL n_l = root->val;
            get_max(n_l, l);
            if (root->right->val > n_l && root->right->val < r)
                tag = tag && dfs(root->right, n_l, r);
            else
                return false;
        }
        return tag;
    }

public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)   return true;
        return dfs(root, - maxll, maxll);
    }
};

int main() {
    Solution solution = Solution();
    TreeNode *node1 = new TreeNode(1), *node2 = new TreeNode(2), *node3 = new TreeNode(3);
    node2->left = node1, node2->right = node3;
    cout << solution.isValidBST(node2) << endl;
    return 0;
}
