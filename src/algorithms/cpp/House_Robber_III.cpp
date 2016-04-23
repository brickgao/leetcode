#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
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
    pair <int, int> dfs(TreeNode *node) {
        int v0 = 0, v1 = 0;
        if (node->left) {
            auto nxt = dfs(node->left);
            v1 += nxt.first;
            v0 += max(nxt.first, nxt.second);
        }
        if (node->right) {
            auto nxt = dfs(node->right);
            v1 += nxt.first;
            v0 += max(nxt.first, nxt.second);
        }
        return make_pair(v0, v1 + node->val);
    }

public:
    int rob(TreeNode *root) {
        if (root == nullptr)    return 0;
        queue <TreeNode *> q;
        pair <int, int> ret = dfs(root);
        return max(ret.first, ret.second);
    }
};


int main() {
    return 0;
}
