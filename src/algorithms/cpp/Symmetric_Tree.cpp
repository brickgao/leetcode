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
    bool dfs(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL) {
            if (p == NULL && q == NULL)     return true;
            else                            return false;
        }
        if (p->val != q->val)   return false;
        return (dfs(p->left, q->right) && (dfs(p->right, q->left)));
    }

public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)       return true;
        return dfs(root->left, root->right);
    }
};

int main() {
    TreeNode *node11 = new TreeNode(1);
    TreeNode *node21 = new TreeNode(2), *node22 = new TreeNode(2);
    TreeNode *node31 = new TreeNode(2), *node32 = new TreeNode(4), *node33 = new TreeNode(4), *node34 = new TreeNode(3);
    node11->left = node21, node11->right = node22;
    node21->left = node31, node21->right = node32, node22->left = node33, node22->right = node34;
    Solution solution = Solution();
    cout << solution.isSymmetric(node11) << endl;
    return 0;
}
