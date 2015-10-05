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
    bool flag;

private:
    int dfs(TreeNode *root) {
        int left_depth = 0, right_depth = 0;
        if (root == NULL)
            return 0;
        if (root->left)
            left_depth = dfs(root->left);
        if (root->right)
            right_depth = dfs(root->right);
        if (abs(left_depth - right_depth) > 1)
            flag = flag && false;
        return max(left_depth, right_depth) + 1;
    }
    
public:
    bool isBalanced(TreeNode *root) {
        flag = true;
        dfs(root);
        return flag;
    }
};

int main() {
    return 0;
}
