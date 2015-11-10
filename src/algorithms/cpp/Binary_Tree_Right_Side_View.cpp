#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
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
public:
    vector<int> rightSideView(TreeNode* root) {
        queue <TreeNode *> q;
        vector <int> result;
        if (root == NULL)       return result;
        TreeNode *end = root, *nxt_end = root;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)     q.push(node->left), nxt_end = node->left;
            if (node->right)    q.push(node->right), nxt_end = node->right;
            if (node == end) {
                result.push_back(node->val);
                end = nxt_end;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
