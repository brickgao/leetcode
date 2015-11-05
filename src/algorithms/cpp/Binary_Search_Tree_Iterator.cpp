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
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    TreeNode *root;
    stack <int> st;

public:
    BSTIterator(TreeNode *root) {
        if (root)   this->dfs(root);
    }

    void dfs(TreeNode *node) {
        if (node->right)
            dfs(node->right);
        this->st.push(node->val);
        if (node->left)
            dfs(node->left);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!this->st.empty());
    }

    /** @return the next smallest number */
    int next() {
        int ret = this->st.top();
        this->st.pop();
        return ret;
    }
};

int main() {
    TreeNode *node11 = new TreeNode(2), *node21 = new TreeNode(1);
    node11->left = node21;
    BSTIterator i = BSTIterator(node11);
    while (i.hasNext()) cout << i.next() << endl;
    return 0;
}
