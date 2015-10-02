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
    vector <int> preorder, inorder;

private:
    TreeNode* build(int prel, int prer, int inl, int inr) {
        int root = this->preorder[prel];
        int index = -1;
        for (int i = inl; i < inr; ++ i)
            if (this->inorder[i] == root) {
                index = i;
                break;
            }
        TreeNode *root_node = new TreeNode(root);
        if (index - inl > 0)
            root_node->left = build(prel + 1, prel + index - inl + 1, inl, index);
        if (inr - index - 1 > 0)
            root_node->right = build(prel + index - inl + 1, prer, index + 1, inr);
        return root_node;
    }

public:
    TreeNode* buildTree(vector <int> &preorder, vector <int> &inorder) {
        this->preorder = preorder, this->inorder = inorder;
        if (SZ(preorder) == 0)      return NULL;
        return build(0, SZ(preorder), 0, SZ(inorder));
    }
};

int main() {
    return 0;
}
