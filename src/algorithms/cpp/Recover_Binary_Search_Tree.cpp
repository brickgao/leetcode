#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
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
    vector < pair <TreeNode*, TreeNode*> > v;
    
private:
    void dfs(TreeNode* root) {
        stack <TreeNode*> st;
        TreeNode *now = root, *pre = NULL;
        while (now || !st.empty()) {
            while (now) {
                st.push(now);
                now = now->left;
            }
            TreeNode *tmp = st.top();
            st.pop();
            if (pre && tmp->val <= pre->val)
                v.push_back(make_pair(pre, tmp));
            pre = tmp, now = tmp->right;
        }
    }

public:
    void recoverTree(TreeNode* root) {
        if (root == NULL)   return;
        dfs(root);
        if (SZ(v) == 1)
            swap(v[0].first->val, v[0].second->val);
        else
            swap(v[0].first->val, v[1].second->val);
    }
};

int main() {
    Solution solution = Solution();
    TreeNode *node1 = new TreeNode(1), *node2 = new TreeNode(2), *node3 = new TreeNode(3);
    node3->left = node1, node3->right = node2;
    solution.recoverTree(node3);
    cout << node3->val << " " << node3->left->val << " " << node3->right->val << endl;
    return 0;
}
