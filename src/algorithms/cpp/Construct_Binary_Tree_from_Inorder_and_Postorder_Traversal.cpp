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
    vector <int> inorder, postorder;

private:
    TreeNode* build(int inl, int inr, int postl, int postr) {
        int root = this->postorder[postr - 1];
        int index = -1;
        for (int i = inl; i < inr; ++ i)
            if (this->inorder[i] == root) {
                index = i;
                break;
            }
        TreeNode *root_node = new TreeNode(root);
        if (index - inl > 0)
            root_node->left = build(inl, index, postl, postl + index - inl);
        if (inr - index - 1 > 0)
            root_node->right = build(index + 1, inr, postl + index - inl, postr - 1);
        return root_node;
    }

public:
    TreeNode* buildTree(vector <int> &inorder, vector <int> &postorder) {
        this->inorder = inorder, this->postorder = postorder;
        if (SZ(inorder) == 0)       return NULL;
        return build(0, SZ(inorder), 0, SZ(postorder));
    }
};

int main() {
    return 0;
}
