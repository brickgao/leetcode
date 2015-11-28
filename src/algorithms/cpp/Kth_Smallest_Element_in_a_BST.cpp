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
    int cnt, result;

private:
    void dfs(TreeNode *root) {
        if (root->left) {
            if (cnt > 0)    dfs(root->left);
        }
        cnt --;
        if (cnt == 0)   result = root->val;
        if (root->right) {
            if (cnt > 0)    dfs(root->right);
        }
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        this->cnt = k;
        dfs(root);
        return result;
    }
};

int main() {
    return 0;
}
