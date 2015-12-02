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

class Solution {
private:
    vector <TreeNode *> tmp_path;

private:
    void dfs(TreeNode *root, TreeNode *target, vector <TreeNode *> &path) {
        if (root == target) {
            path = tmp_path;
            return;
        }
        if (root->left) {
            tmp_path.push_back(root->left);
            dfs(root->left, target, path);
            tmp_path.pop_back();
        }
        if (root->right) {
            tmp_path.push_back(root->right);
            dfs(root->right, target, path);
            tmp_path.pop_back();
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector <TreeNode *> p_path, q_path;
        tmp_path.push_back(root);
        dfs(root, p, p_path);
        dfs(root, q, q_path);
        tmp_path.pop_back();
        for (int i = 0; i < min(SZ(p_path), SZ(q_path)); ++ i) {
            if (p_path[i] != q_path[i])     return p_path[i - 1];
        }
        return p_path[min(SZ(p_path), SZ(q_path)) - 1];
    }
};

int main() {
    return 0;
}
