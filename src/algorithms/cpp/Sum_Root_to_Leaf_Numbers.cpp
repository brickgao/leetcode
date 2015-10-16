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
    void dfs(TreeNode *root, int val) {
        bool tag = false;
        if (root->left)     tag = true, dfs(root->left, val * 10 + root->left->val);
        if (root->right)    tag = true, dfs(root->right, val * 10 + root->right->val);
        if (!tag)           result += val;
    }

public:
    int sumNumbers(TreeNode* root) {
        result = 0;
        if (root)   dfs(root, root->val);
        return result;
    }
};

int main() {
    return 0;
}
